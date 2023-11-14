#include <vector>
#include <iostream>
#include <functional>
using namespace std::placeholders;

class Rect 
{
public:
	void draw() { std::cout << "draw" << std::endl;}
};

int main()
{
	std::vector<Rect*> v;

	v.push_back( new Rect);
	v.push_back( new Rect);
	v.push_back( new Rect);

	// v 의 모든 요소에 대해서 draw()를 호출해 봅시다.

	// 방법 1. range for
	for( auto e : v)
		e->draw();

	// 방법 2. for_each 와 람다 표현식
	std::for_each(v.begin(), v.end(), [](Rect* e){e->draw();});


	// 방법 3. for_each 와 std::bind
	// => 아래 코드가 좀 어려운 형태 인데.. 의미는
	// => v의 모든 요소(Rect*) 에 대해서 draw() 멤버 함수를 호출해 달라. 
	// => 즉, _1 자리에 v안에 있는 각 객체를 전달해 달라.
	// => 인자를 bind 한것이 아니라 객체를 bind 하는 의미!
	std::for_each(v.begin(), v.end(), std::bind(&Rect::draw, _1));
								    
}