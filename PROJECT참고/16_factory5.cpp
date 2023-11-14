#include <iostream>
#include <vector>
#include <map>

class Shape
{
public:
	virtual ~Shape() {}
	virtual void draw() = 0;
};

// #1. ShapeFactory 클래스의 위치를 Shape 아래, Rect 위로 옮겼습니다.
//     그리고 ShapeFactory 에 싱글톤 기술을 적용했습니다.
//     어디서든지 ShapeFactory 객체가 필요 하면 ShapeFactory::get_instance() 를 호출하면 됩니다.
class ShapeFactory
{
	using CREATOR = Shape*(*)(); 

	std::map<int, CREATOR> m; 
public:
	void register_shape(int type, CREATOR f)
	{
		m[type] = f;
	}
	
	Shape* create(int type)
	{
		Shape* s = nullptr;
		CREATOR f = m[type]; 

		if ( f != nullptr )
			s = f(); 
					
		return s;
	}
	// 싱글톤 코드
	static ShapeFactory& get_instance()
	{
		static ShapeFactory factory;
		return factory;
	}
};
//=============
// #2. 아래 클래스가 핵심 입니다.
class AutoRegister
{
public:
	AutoRegister(int type, Shape*(*f)() )
	{
		// 생성자에서 공장의 참조를 얻어서 제품을 등록합니다.
		ShapeFactory& factory = ShapeFactory::get_instance();
		factory.register_shape(type, f);
	}
};

// 전역변수의 생성자는 main 함수 보다 먼저 호출됩니다.
// 따라서 아래 한줄이 있으면 main 이 시작 되기 전에 이미 Rect 가 공장에 등록 됩니다.
// AutoRegister ar(1, &Rect::create);
//			=> 물론 이코드의 주석을 풀면 Rect 클래스가 아래 있기 때문에 에러 입니다.
//			=> 그냥, 전역변수의 생성자가 main 보다 먼저 호출된다고 알아 두세요

//======================


class Rect   : public Shape
{
public:
	void draw() override { std::cout << "draw rect\n"; }

	static Shape* create()
	{
		Rect* p = new Rect;

		return p;
	}

	// #3. static 멤버 데이타는 "반드시 외부 정의"가 필요 합니다.
	//     그리고 static 멤버 변수는 객체를 만들지 않아도 메모리에 놓이게 되고
	//     static 멤버 데이타의 생성자는 main 함수 보다 먼저 호출됩니다.
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);

// 핵심 : 위 ar 이라는 멤버 때문에(생성자가 호출되었기 때문에) 
//       이미 Rect 가 공장에 등록되었습니다.
//       main 에서 따로 등록할 필요 없습니다.
//       이제 모든 제품에 동일하게 ar 을 제공합니다.





class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle\n"; }
	static Shape* create()
	{
		Circle* p = new Circle;
		return p;
	}	
	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::create);



int main()
{
	std::vector<Shape*> v;

	// 1. 공장의 참조를 얻어 옵니다.
	//    이미 제품은 등록되어 있는 상태 입니다.
	ShapeFactory& factory = ShapeFactory::get_instance();


	int cmd;
	std::cin >> cmd;

	Shape* s = factory.create(cmd);

	if ( s )
		v.push_back(s);	

	v[0]->draw();
}

// 위 코드의 의미는 공장에 제품을 등록하는 것을
// "각 도형 클래스가 스스로" 하고 있다는 점입니다.

// 따라서, 새로운 도형이 추가되면 아래 처럼만 만들면 
// 기존 코드를 어디도 변경하지 않아도 즉시 사용가능합니다.

class Triangle  : public Shape
{
public:
	void draw() override { std::cout << "draw triangle\n"; }
	static Shape* create()
	{
		Triangle* p = new Triangle;

		return p;
	}	
	static AutoRegister ar;
};
AutoRegister Triangle::ar(3, &Triangle::create);