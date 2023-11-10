// function1.cpp
#include <iostream>
#include <functional> // std::bind 사용하기 위해
using namespace std::place_holders; // 1_, _2, _3

void f4(int a, int b, int c, int d)
{
	// 변수를 여러개 출력할때는 cout 보다 printf 가 편리하긴 합니다!
	printf("f4 : %d, %d, %d, %d\n", a, b, c, d);
}
int main()
{
	f4(1,2,3,4);

	// std::bind : N항 함수의 일부(전부)인자를 고정한 새로운 함수를 만드는 도구

	// 사용법 : std::bind( N항 함수주소, N개의 인자)

	auto f0 = std::bind(&f4, 1, 2, 3, 4); // f4 의 인자 4개를 모두 고정한 새로운 함수
	f0(); // f4(1,2,3,4);				// 결국 4항 함수 => 0항 함수로 만든것


	auto f2 = std::bind(&f4, 6, _1, 7, _2); // 4항 함수 => 2항 함수로 만든것
	f2(3, 9); // f4(6, 3, 7, 9)


	auto f3 = std::bind(&f4, _2, _3, 8, _1); 
	f3(9, 3, 7); // f4(3, 7, 8, 9)
}








