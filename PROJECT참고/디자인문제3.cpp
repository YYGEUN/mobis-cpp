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

// 먼저 이 코드를 실행해서 1 또는 2을 몇번 입력 하세요
// 9번을 입력하면 현재 까지 만든 모든 도형을 화면에 출력하게 됩니다.
// 1, 2, 9 에 대한 if 문을 이해 하신분은
// => 8번 입력했을때 주석을 보세요.. 문제를 해결해 보세요

int main()
{
	std::vector<Shape*> v;
	
	while(1)
	{
		int cmd;
		std::cin >> cmd;

		if ( cmd == 1 ) 
			v.push_back( new Rect);

		else if ( cmd == 2 )
			v.push_back( new Circle);

		else if ( cmd == 9 )
		{
			// 만들었던 모든 도형 그리기
			for( auto e : v)
				e->draw();
		}
		else if ( cmd == 8 )
		{
			// # 핵심!!
			// 파워 포인트에는 "copy & paste" 기능이 있습니다.
			// => 기존 도형을 선택해서 "CV" 하면 완전히 동일한 도형이 한개 더 추가됩니다.
			// => 해당 기능은 어떻게 구현해야 할까요 ?
			// => 아래 코드를 완성해 보세요 

			std::cout << "몇 번째 도형을 복사할까요 >> ";
			int cmd;
			std::cin >> cmd;

			// v 에 있는 도형중에서 cmd 번째 있는 도형의 복사본을 만들어서
			// v 에 추가 합니다.
			// 어떻게 해야 할까요 ? v[cmd] 가 가진 도형은 어떤 도형 일까요 ?
			// 최선의 코드를 찾아 보세요!!
		}
	}
	
}
