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

// 이제 위 코드에서 새로운 제품(Triangle 같은 도형)이 추가되면 88~89 번째 줄처럼 하면 됩니다.
// => factory.register_shape(3, &Circle::create)

// => 결국 새로운 도형이 추가되어도 "기존 코드가 수정" 되긴 합니다.
// => 그래도, case 문의 추가가 아닌 "제품의 등록" 이라는 개념이 되었으므로 훨씬 보기는 좋습니다.

// ==> 그런데,, 자동 등록되게 할수 없나요 ???
// ==> 가능합니다!! 다음 예제