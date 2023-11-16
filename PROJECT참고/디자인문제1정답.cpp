#include <iostream>
#include <vector>

class Shape
{
public:
	// 그림을 그리기 위해서는
	// 1. "도형의 종류에 상관없이 반드시 해야하는 공통의 초기화 작업과"
	// 2. 각 도형별로 변경해야 하는 작업이 있습니다.

	void draw()
	{
		std::cout << "모든 도형의 공통의 기능을 수행합니다." << std::endl;

		// 각 도형 별로 변해야하는 작업을 가상함수로 분리 합니다.
		draw_imp();
	}
	// 이제 각 도형은 draw_imp() 를 override 하면 됩니다.
	virtual void draw_imp() = 0;

	// 위 draw 처럼
	// 1. 기반 클래스가 전체적인 틀(template) 을 담은 함수(비 가상함수)를 제공하고
	// 2. 변해야 하는 것만 가상함수화 해서 파생클래스가 재정의 할수 있는 기회를 제공하는 것을
	//    "template method" 패턴이라고 합니다.
};

class Rect : public Shape 
{
public:
	void draw_imp() override {	std::cout << "draw rect\n"; }
};

class Circle : public Shape 
{
public:
	void draw_imp() override {	std::cout << "draw circle\n"; }
};

int main()
{
	std::vector<Shape*> v;

	v.push_back( new Rect);
	v.push_back( new Circle);

	for( auto p : v)
		p->draw();
}
