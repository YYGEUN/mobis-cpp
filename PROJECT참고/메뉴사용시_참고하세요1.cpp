#include <iostream>

// std::bind() 와 std::function 을 사용하려면 
// 먼저 아래 2줄이 필요 합니다.
#include <functional>

// 아래 2개의 함수와 1개의 클래스를 참고하고, main 을 보세요
void foo()      {} // 인자가 없는 함수
void goo(int a) {} // 인자가 있는 함수

class HomeAutomationSystem
{
public:
	void add_product() {} // 인자가 없지만, 멤버 함수 입니다.
};

//-------------------------------------
int main()
{
	std::function<void()> f; // 인자가 없는 함수만 담을수 있습니다.

	f = &foo;		// ok. foo 는 인자가 없는 함수
//	f = &goo;		// error. goo 는 인자가 1개 있습니다.

	f = std::bind(&goo, 3); // ok. 인자를 3으로 고정해서 인자가 없는 함수를 만들었습니다.

	// 아래 코드가 핵심입니다. 잘 생각해 보세요
	HomeAutomationSystem h1;
	HomeAutomationSystem h2;

	h1.add_product();	// h1 객체에 대해서 함수 호출
	h2.add_product();	// h2 객체에 대해서 함수 호출

	f = &HomeAutomationSystem::add_product; // error
				// => add_product 는 인자가 없는 함수 지만, 
				// => 일반 함수가 아닌 멤버 함수 입니다
				// => 위처럼 전달하면 f() 를 했을때, 
				//    h1 에 대해서 호출하는지 h2 에 대해서 호출하는지 알수 없습니다.

	// 따라서, 멤버 함수를 function 에 등록 할때는 반드시 객체도 고정해야 합니다.
	// => std::bind() 는 인자 뿐아니라 객체도 고정 가능합니다.

	f = std::bind(&HomeAutomationSystem::add_product, &h1);
	f(); // h1.add_product() 입니다.
}
