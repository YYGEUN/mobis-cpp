#include <iostream>
#include <vector>
#include <map>

// 다양한 테크닉을 적용한 공장을 만들어 봅시다.

class Shape
{
public:
	virtual ~Shape() {}
	virtual void draw() = 0;
};


class Rect   : public Shape
{
public:
	void draw() override { std::cout << "draw rect\n"; }

	// 핵심 #1. 모든 제품(도형)은 자신을 스스로 만드는 정적 멤버 함수 "create" 를 제공하기로 약속합니다.
	static Shape* create()
	{
		// std::cin 등으로 이름, 색상등 도형의 속성을 입력 받고

		Rect* p = new Rect; // new Rect(10,20, 이름... 등으로 생성)

		return p;
	}
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle\n"; }
	static Shape* create()
	{
		Circle* p = new Circle;
		return p;
	}	
};
// 핵심 #2. 아래 주석을 이해 하세요
// 이제 Circle 를 만드는 방법은 2개 입니다.
// 1. Circle* c1 = new Circle;
// 2. Circle* c2 = Circle::create(); 

// 1번은 객체를 만들기 위해 클래스 이름(Circle) 를 사용하지만
// 2번은 객체를 만들기 위해 함수 호출을 한다는 점이 핵심 입니다.
// 클래스 이름은 map 에 보관될수 없지만, 함수 주소는 map 에 보관 가능합니다.
// => 아래 Factory 를 보세요

class ShapeFactory
{
	// 핵심 #3. 공장에는 제품번호와 제품을 만드는 생성함수를 보관하기로 합니다.
	using CREATOR = Shape*(*)(); // 함수 포인터 타입.

	std::map<int, CREATOR> m; // 도형 번호를 키값으로 도형을 만드는 함수를 보관
public:
	void register_shape(int type, CREATOR f)
	{
		// 공장의 맵에 "타입번호"와 "생성함수" 를 등록합니다.
		m[type] = f;
	}
	
	// 핵심 #4. 제품을 만들때 맵에 등록된 함수를 사용합니다.
	Shape* create(int type)
	{
		Shape* s = nullptr;

		CREATOR f = m[type]; // map 에서 등록된 함수 주소를 꺼냅니다.

		// type 이 잘못된 번호라면 0이 나오므로 유효할때만 사용합니다.
		if ( f != nullptr )
			s = f(); // 이제 도형이 생성되었습니다
					
		return s;
	}
};

int main()
{
	std::vector<Shape*> v;

	// 핵심 #5. 이제 공장은 아래 처럼 사용합니다.

	// 1. 공장을 건설하고
	ShapeFactory factory;

	// 2. 공장에 제품(생성함수)를 등록합니다.
	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);

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