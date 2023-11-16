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

			// #1. dynamic_cast 사용
			if ( dynamic_cast<Rect*>(v[no]) )
			{
				Rect* r = static_cast<Rect*>(v[no]);

				v.push_back( new Rect( *r ) );
			}
			else if ( dynamic_cast<Circle*>(v[no]) )
			{
				Circle* c = static_cast<Circle*>(v[no]);

				v.push_back( new Circle( *c ) );
			}

			// 단점 : 위 처럼 하면 새로운 도형(Triangle) 이 추가되면 
			//      if 문이 한줄 더추가되어야 합니다.
			//      OCP 위반
		}
	}
	
}
