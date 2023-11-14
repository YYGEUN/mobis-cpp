#include <memory>
#include <iostream>

class Rect 
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
};

int main()
{	
	// #1. 메모리를 동적으로 할당하면 반드시 해지 해야 합니다.
	// C 언어 스타일
	Rect* p1 = (Rect*)malloc(sizeof(Rect));
	free(p1);

	// C++ 스타일
	Rect* p2 = new Rect(0, 0, 10, 10);
	delete p2;

	// #2. 스마트 포인터를 사용하면 자동으로 delete 하는 기능이 추가 되므로 편리합니다.
	// 반드시 <memory> 헤더를 추가 해야 합니다.
	std::shared_ptr<Rect> p3 = std::make_shared<Rect>(0, 0, 10, 10);

	// 위 코드가 복잡해 보이지만 결국 아래 처럼 변경된 것입니다.
	// Rect*                  ==> std::shared_ptr<Rect>
	// new Rect(0, 0, 10, 10) ==> std::make_shared<Rect>(0, 0, 10, 10)

	// 즉, 왼쪽 처럼 작성된 코드를 오른쪽 코드로만 변경하면 "자동 삭제" 기능이 추가됩니다.

	// 생성자 인자가 없을 경우는 아래 처럼만 하면 됩니다.
	// new Rect ==> std::make_shared<Rect>()
}
// 위 주석을 잘보고 PROJECT 에 스마트 포인터를 도입해 보세요
// ptr2.cpp 는 금요일날 만든 메뉴를 스마트 포인터로 변경한 코드 입니다.
