#include <iostream>
#include <vector>

// 파워 포인트 같은 프로그램을 만드는 것을 생각해 봅시다.

// 1. 모든 도형을 "타입" 으로 설계하면 편리하다.

// 2. 모든 도형의 공통의 기반 클래스가 있다면 모든 종류의 도형을 하나의 vector에 보관 가능하다.

class Shape 
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
	int x, y, width, height;
public:
	Rect(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) 	{}
	void draw() { std::cout << "draw rect" << std::endl;}
};

class Circle : public Shape
{
	int x, y, radius;
public:
	Circle(int x, int y, int r) : x(x), y(y), radius(r) {}
	void draw() { std::cout << "draw circle" << std::endl;}
};


int main()
{
//	std::vector<Rect*> v; // Rect 객체 주소만 보관가능한 vector
	std::vector<Shape*> v; // 모든 도형을 보관 가능한 vector

	while(1)
	{
		int cmd;
		std::cin >> cmd;

		if ( cmd == 1 )
		{
			Rect rc(0, 0,100,100);
		}
		else if ( cmd == 2 )
		{

		}
		else if ( cmd == 9 )
		{
			
		}
	}

}


