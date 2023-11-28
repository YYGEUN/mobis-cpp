#include <iostream>
#include <vector>

#define PI 3.14;

using namespace std;

// 파워 포인트 같은 프로그램

//1. 도형을 class로 설계

//2. 모든도형의 공통기반 클래스가 있다면 모든종류의 도형을 하나의 vector에 보관가능

//3. 모든 도형의 공통 특성은 반드시 기반클래스로부터 유래되어야함 ex) draw
//	 Shape*로 해당특성을 사용하기위함
//	 문법적이아닌 디자인 측면의 규칙

//4. 기반클래스가 가진 멤버함수중 파생클래스가 override하는 것은 반드시 가상함수

class shape
{
protected:
	int color;
public:
	virtual ~shape() {}

	void set_color(int c) { color = c; } // 자식클래스가 override 할필요가없음(non-virtual)

	// 가상함수 : 파생클래스가 override 하지않으면 자신의것을 물려줌
	virtual void show() { cout << "shape show" << endl; }

	// 순수 가상함수 --> override 안하면 error
	virtual void draw() = 0;

	// 순수 가상함수로 필수 재정의를 요구할 수도있고
	// -1등.. defalut 리턴으로 표시할수있음
	virtual int get_area() { return -1; }
};

class Triangle:public shape
{
public:
	virtual void draw() { cout << "draw triangle" << endl; }
	virtual int get_area() { return 100; }
};

class Rect : public shape
{
	int x, y, width, height;
public:
	Rect(int x, int y, int w, int h) :x(x), y(y), width(w), height(h)
	{

	}
	void draw() override { cout << "draw rect" << endl; }
	int get_area() override { return width * height; }
};

class Circle : public shape
{
	int x, y, radius;
public:
	Circle(int x, int y, int r) :x(x), y(y), radius(r)
	{

	}
	void draw() override { cout << "draw circle" << endl; }
	int get_area() override { return radius * radius * PI; }
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
		else if (cmd == 3)
		{
			v.push_back(new Triangle);
		}
		else if (cmd == 9)
		{
			for (auto p : v) {
				p->draw(); // 에러 p의타입이 shaep 이기때문에 
			}
		}
	}

}