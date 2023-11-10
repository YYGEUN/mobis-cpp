#include <iostream>
#include <vector>

// 파워 포인트 같은 프로그램을 만드는 것을 생각해 봅시다.

// 1. 모든 도형을 "타입" 으로 설계하면 편리하다.

class Rect
{
	int x, y, width, height;
public:
	Rect(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) 	{}
	void draw() { std::cout << "draw rect" << std::endl;}
};

class Circle
{
	int x, y, radius;
public:
	Circle(int x, int y, int r) : x(x), y(y), radius(r) {}

	void draw() { std::cout << "draw circle" << std::endl;}
};


int main()
{
	Rect r(0, 0, 100, 100);
	r.draw();

	Circle c(0, 0, 50);
	c.draw();

}


