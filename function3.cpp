// function1.cpp
#include <iostream>
#include <functional> // std::bind 사용하기 위해
using namespace std::placeholders; // 1_, _2, _3

void f4(int a, int b, int c, int d)
{
	printf("f4 : %d, %d, %d, %d\n", a, b, c, d);
}
void f1(int a)        { printf("f1 : %d\n",     a);}
void f2(int a, int b) { printf("f2 : %d, %d\n", a, b);}

class Dialog
{
public:
	void close(int result, int arg) {}
};

int main()
{
	std::function<void(int)> f; 

	// f에는 인자가 한개인 함수만 담을수 있습니다
	// 그런데, std::bind 가 있으므로 결국 인자가 1개 이상인 모든 함수를 담을수 있습니다.

	f = &f1;
	f = std::bind(&f2, _1, 0);
	f = [](int a) { std::cout << "람다표현식도 가능\n";};

	// 멤버 함수를 고정하려면 객체도 고정되어야 합니다.
	Dialog dlg;
	f = std::bind(&Dialog::close, &dlg, _1, 3);
	f(5); // dlg.close(5, 3);
	
}








