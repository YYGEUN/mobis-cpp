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
	int code;
public:
	void close()   // void close(Dialog* this)
	{
		code = 10; // this->code = 10;
	} 
};
void foo() {}
void goo(int a) {}

int main()
{
	std::function<void()> f; 

	f = &foo;
	f = std::bind(&goo, 3); //
	f(); // goo(3);

	Dialog dlg1;
	Dialog dlg2;
	dlg1.close();  // close(&dlg1)

	// 멤버 함

	f = &Dialog::close; // error. this 라는 인자가 있다.
	f = std::bind(&Diglog::close, &dlg1);
	f(); // dlg1.close()

	
}








