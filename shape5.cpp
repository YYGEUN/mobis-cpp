#include <iostream>
#include <vector>

// 파워 포인트 같은 프로그램을 만드는 것을 생각해 봅시다.

// 1. 모든 도형을 "타입" 으로 설계하면 편리하다.

// 2. 모든 도형의 공통의 기반 클래스가 있다면 모든 종류의 도형을 하나의 vector에 보관 가능하다.

// 3. 모든 도형의 공통의 특징은 반드시 기반 클래스인 Shape 에도 있어야 한다.
//    그래야지, Shape* 로 해당 특징을 사용할수 있다.
//    => 문법적인 규칙이 아닌, 디자인 측면에서의 규칙!!

// 4. 기반 클래스가 가진 멤버 함수중에서 "파생 클래스가 override" 하게 되는 것은 반드시
//    가상함수로 설계 되어야 한다.!!

class Shape 
{
protected:
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c;}

	// 가상함수    : 파생 클래스가 "override" 하지 않아도 된다. 기본 구현을 물려 주겠다는 의도
	// 순수가상함수 : 파생 클래스에게 반드시 해당 함수를 만들라고 지시하는 것

	// Shape 에 순수 가상함수가 있으므로 Shape 는 추상클래스 이다. 객체를 만들수 없다.
	// Shape s; // error.  당연하다!! "도형" 이라는 객체는 현실세계에 존재 하지 않는다.

	virtual void draw() = 0; //{ std::cout << "draw shape\n"; }

	// 아래 함수도
	// 1. 순수 가상함수로 해서, 모든 파생 클래스에게 반드시 만들라고 해도 되고!!
	// 2. -1 등을 반환해서, 혹시 get_area() 호출시 결과가 -1 나오면 "면적 구할수 없음" 으로
	//   약속해도 됩니다.
	virtual int get_area() { return -1;}
};


class Triangle : public Shape 
{
public:
	// Shape 의 순수 가상함수인 draw() 를 반드시 만들어야 한다.!!
	// 만들지 않으면 Triangle 도 추상 클래스라서 "객체 생성 안됨"
	// Triangle t; // error

	// 물론, 객체를 생성하는 코드가 없다면 에러는 아님.
};





class Rect : public Shape
{
	int x, y, width, height;
public:
	Rect(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) 	{}

	void draw() override { std::cout << "draw rect" << std::endl;}
};

class Circle : public Shape
{
	int x, y, radius;
public:
	Circle(int x, int y, int r) : x(x), y(y), radius(r) {}

	void draw() override { std::cout << "draw circle" << std::endl;}
};


int main()
{
	std::vector<Shape*> v;
	while(1)
	{
		int cmd;
		std::cin >> cmd;

		if      ( cmd == 1 ) v.push_back( new Rect(0, 0, 100, 100) );
		else if ( cmd == 2 ) v.push_back( new Circle( 0, 0, 50));
		
		else if ( cmd == 9 )
		{
			for( auto p : v)
				p->draw(); 		
		}
	}

}


