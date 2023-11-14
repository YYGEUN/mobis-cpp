#include <iostream>
#include <functional>
using namespace std::placeholders;

// 핵심 : f1 의 인자가 참조 입니다.!!
void f1(int& a) { a = 100; }

int main()
{
	std::function<void()> f;

	int n1 = 0;
	f = std::bind( &f1, n1); // 이렇게 하면 n1 자체가 고정되는 것이 아니라
							 // n1 값(0)을 내부적으로 복사본에 보관해서 고정합니다.
							 // "n1 자체가 고정된것이 아니라는 의미"
							 
	f(); // f1(n1) 이 아닌 f1(n1의 값을 복사했던 복사본)
		 // 따라서 f1()에서 참조로 받아서 a = 100 을 했지만
		 // n1 자체는 변경되지 않았습니다.

	std::cout << n1 << std::endl; // 0;



	// n1의 값이 아닌 n1 자체를 고정하려면 std::ref() 사용해야 합니다.
	f = std::bind(&f1, std::ref(n1)); // n1 을 참조로 고정해달라는 의미
	f();
	std::cout << n1 << std::endl; // 100 입니다.
}