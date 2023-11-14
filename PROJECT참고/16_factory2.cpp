#include <iostream>
#include <vector>

class Shape{};
class Rect   : public Shape{};
class Circle : public Shape{};

// 다양한 도형을 만들때, 코드의 여러곳에서 만들지 말고
// 한곳에서 만들어 줍니다.
// 이런 기법을 "공장(Factory)" 라고 합니다.
class ShapeFactory
{
public:
	Shape* create(int type)
	{
		Shape* s = nullptr;
		switch(type)
		{
			case 1: s = new Rect; break;
			case 2: s = new Circle; break;
		}
	}
};

int main()
{
	std::vector<Shape*> v;

	// 제품(도형)을 만들기 위한 공장을 건설(객체 생성) 합니다.
	ShapeFactory factory;

	int cmd;
	std::cin >> cmd;

	// 이제 모든 제품은 공장을 통해서만 만들어야합니다.
	Shape* s = factory.create(cmd);

	if ( s )
		v.push_back(s);	
}
// 장점 : 이제 새로운 도형이 추가되어도 main 코드가 수정될 필요 없습니다.

// 그런데 ? 새로운 도형이 추가되면 "공장은 수정" 되어야 하지 않나요 ?
// ==> 맞습니다.
// ==> 그래도 장점은, 객체의 생성이 한곳에 집중 되어 있으므로 새로운 도형 추가시 한곳 만 변경되면 됩니다.
// ==> 그리고, 다양한 테크닉으로 공장을 더욱 좋게 만들면 됩니다.(다음 소스 참고)


