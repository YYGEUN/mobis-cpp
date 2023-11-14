#include <iostream>
#include <vector>

// OCP 이론
// => Open Close Principle 이라는 이론
// => 기능 추가에 "열려있고(Open)"
// => 코드 수정에 "닫혀 있어야(Close)" 한다는 이론(Principle)
// => "새로운 요소가 추가되어도 기존 코드는 수정되지 않게 하라는 이론" 입니다.

// 위 이론을 참고 해서 아래 코드를 보세요

class Shape{};
class Rect   : public Shape{};
class Circle : public Shape{};

int main()
{
	std::vector<Shape*> v;

	int cmd;
	std::cin >> cmd;
	

	// 아래 코드의 문제점은 새로운 도형이 추가되면
	// "case" 구문에 한개 더 추가되게 됩니다.
	// OCP 위반 입니다.
	switch(cmd)
	{
		case 1: v.push_back( new Rect); break;
		case 2: v.push_back( new Circle); break;
	}
}

