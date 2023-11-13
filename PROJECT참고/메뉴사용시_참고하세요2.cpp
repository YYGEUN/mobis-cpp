#include "menu.h"

void foo() {}

class HomeAutomationSystem
{
public:

	void init_menu()
	{
		// MenuItem 의 3번째 인자는 "인자가 없는 함수주소" 를 보내야 합니다.
		new MenuItem("제거", 11, &foo); // ok.. foo 는 인자가 없는 함수 입니다.
//		new MenuItem("등록", 11, &HomeAutomationSystem::add_product); // error
									// 인자가 없는 함수 지만, 멤버 함수 입니다. 
									// 반드시 std::bind 로 객체를 고정해야 합니다.
									// init_menu 함수가 멤버 함수 이므로 객체는 "this" 입니다.

		// 따라서 아래 처럼 해야 합니다.
		new MenuItem("등록", 12, std::bind(&HomeAutomationSystem::add_product, this) ); // ok

		// 위 코드를 이해 한후에 "skeleton.cpp" 를 보세요
	}

	void add_product() {} 
};

//-------------------------------------
int main()
{

}
