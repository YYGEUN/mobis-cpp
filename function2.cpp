// function1.cpp
#include <iostream>
#include <functional> // std::bind 사용하기 위해
using namespace std::place_holders; // 1_, _2, _3

void f4(int a, int b, int c, int d)
{
	printf("f4 : %d, %d, %d, %d\n", a, b, c, d);
}
void f1(int a)        { printf("f1 : %d\n",     a);}
void f2(int a, int b) { printf("f2 : %d, %d\n", a, b);}

int main()
{
	// C의 함수 포인터는 너무 불편합니다.
	void(*f)(int) = &f1; 
	f(10); // f1(10)

	f = &f2; // error. 인자의 모양의 다름!

}








