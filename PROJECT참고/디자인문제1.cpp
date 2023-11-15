#include <iostream>
#include <vector>

class Shape
{
public:
	virtual void draw() = 0;
};

class Rect : public Shape 
{
public:
	void draw() override {	std::cout << "draw rect\n"; }
};

class Circle : public Shape 
{
public:
	void draw() override {	std::cout << "draw circle\n"; }
};

int main()
{
	std::vector<Shape*> v;

	v.push_back( new Rect);
	v.push_back( new Circle);

	for( auto p : v)
		p->draw();
}

// 위 코드를 실행하면 아래 처럼 나오게 됩니다.
// "draw rect"
// "draw circle"

// 그런데, 그림을 그릴때는 그림을 그리기 위해 초기화 작업이 필요하다고 가정해 봅시다.
// 결과를 아래 처럼나오게 코드를 변경해 보세요 - 최선의 디자인을 찾아보세요

// "그리기 위한 초기화 작업"
// "draw rect"
// "그리기 위한 초기화 작업"
// "draw circle"