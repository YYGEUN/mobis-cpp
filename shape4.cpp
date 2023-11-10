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
	int color; // 모든 도형은 색상이 있다.

public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw shape\n"; }

	// 아래 멤버 함수는 "virtual" 로 할까요 ? 하지 말까요 ?
	// => 파생 클래스가 이 함수를 override 할 이유는 없다.!! 
	// => non-virtual
	void set_color(int c) { color = c;}

	// 모든 도형은 면적를 구할수 있다. virtual ? non-virtual
	// => 모든 도형은 면적을 구하는 방법이 다르다.!!
	// => override 해야 한다.
	// => virtual
	virtual int get_area() { return 0;}
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


