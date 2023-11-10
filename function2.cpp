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

int main()
{
	// C의 함수 포인터는 너무 불편합니다.
//	void(*f)(int) = &f1; 
//	f(10); // f1(10)
//	f = &f2; // error. 인자의 모양의 다름!

	//===============================================
	// STL 의 std::function 이 함수포인터 보다 편리합니다.
	// 사용법 : std::function<함수모양> 

	std::function<void(int)> f; // f가 함수 포인터 처럼 함수의 주소를 보관하는 도구

	f = &f1;
	f(10); // f1(10)

//	f = &f2; // error. f는 인자가 한개인 것의 주소만 가능한데, f2 는 인자가 2개!

	// std::function 의 장점 : std::bind 의 반환값 보관 가능
	// 즉, "2항 함수 => 1항 함수"로 변경해서 담으면 됩니다.
	f = std::bind(&f2, _1, 3);

	f(5); // f2(5, 3)


	// f가 인자 한개인 것만 가능하므로 "4항인 f4 를 1항함수로 변경해서" 담아야 합니다.
	f = std::bind(&f4, 3, 6, _1, 9);
	f(5); // f4(3, 6, 5, 9);
}








