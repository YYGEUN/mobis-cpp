#include <iostream>
#include <vector>

class Shape
{
public:
	virtual void draw() = 0;

	// 핵심 : 모든 도형은 자신의 복사본을 만들수 있는 가상함수를 제공하기로 약속합니다.
	virtual Shape* clone() = 0;
};

class Rect : public Shape 
{
public:
	void draw() override {	std::cout << "draw rect\n"; }

	Shape* clone() override { return new Rect(*this); }
};

class Circle : public Shape 
{
public:
	void draw() override {	std::cout << "draw circle\n"; }

	Shape* clone() override { return new Circle(*this); }
};

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
			for( auto e : v)
				e->draw();
		}
		else if ( cmd == 8 )
		{
			std::cout << "몇 번째 도형을 복사할까요 >> ";
			int no;
			std::cin >> no;

			// 정답. no 번째 도형이 무엇인지 조사할 필요 없습니다.
			// 단지, 객체에게 "너와 동일하게 생긴 객체 한개만 만들어 달라" 고 요청하면 됩니다.
			v.push_back( v[no]->clone() );

			// 이제 새로운 도형이 추가되어도 위 한줄은 수정될 필요 없습니다.
			// 단, 모든 도형을 만드는 사람은 반드시 clone() 만들어야 한다는 요구조건이 생기게 됩니다.

			// "새로운 요소" 때문에 "기존 코드가 수정" 되게 하지 말고..
			// 기존 코드에 추가되기 위해 지켜야 하는 "규칙" 을 만드는 것이 좋습니다.
		}
	}	
}

// 위 코드 처럼 "객체가 자신의 복사본을 생성" 할수 있게 하는 디자인 기법을
// "prototype 패턴" 이라고 합니다.