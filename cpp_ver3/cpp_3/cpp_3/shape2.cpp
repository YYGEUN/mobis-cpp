#include <iostream>
#include <vector>
using namespace std;

// �Ŀ� ����Ʈ ���� ���α׷�

class Rect
{
	int x, y, width, height;
public:
	Rect(int x , int y ,int w,int h):x(x),y(y),width(w),height(h)
	{

	}
	void draw() { cout << "draw rect" << endl; }
};

class Circle
{
	int x, y, radius;
public:
	Circle(int x, int y, int r) :x(x), y(y), radius(r)
	{

	}
	void draw() { cout << "draw circle" << endl; }
};


int main()
{
	Rect r(0,0,100,200);
	r.draw();
	Circle c(0, 0, 10);
	c.draw();
}