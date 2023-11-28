#include <iostream>
#include <vector>
using namespace std;

// 파워 포인트 같은 프로그램

//1. 도형을 class로 설계

//2. 모든도형의 공통기반 클래스가 있다면 모든종류의 도형을 하나의 vector에 보관가능

class shape
{
public:
	virtual ~shape() {}
	virtual void draw() = 0;
};

class Rect : public shape
{
	int x, y, width, height;
public:
	Rect(int x, int y, int w, int h) :x(x), y(y), width(w), height(h)
	{

	}
	void draw() { cout << "draw rect" << endl; }
};

class Circle : public shape
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
	vector<shape*> v; // rect,circle 클래스를 모두 받을수있다

	while (1)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			Rect rc(0, 0, 100, 100); // {} 벗어나면 파괴
			Rect* r1 = new Rect(0, 0, 100, 120); // 동적할당하고
			v.push_back(r1); // 주소를 저장
		}
		// rc 파괴됨
		else if (cmd == 2)
		{
			v.push_back(new Circle(0, 0, 17));
		}
		else if (cmd == 9)
		{
			for (auto p : v) {
				p->draw(); // 에러 p의타입이 shaep 이기때문에 
			}
		}
	}

}