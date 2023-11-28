#include <iostream>
#include <functional>
//#include <stdio.h>

using namespace std::placeholders; // _1 등 사용하기위함

void f4(int a, int b, int c, int d) {
	//변수를 여러개 출력할때는 printf가 편함
	printf("f4 : %d, %d, %d, %d\n",a, b, c, d);
}

int main()
{
	f4(1, 2, 3, 4);

	//std::bind N항 함수의 일부(전부) 인자를 고정한 새로운 함수를 만드는 도구

	auto f0 = std::bind(&f4, 5, 2, 3, 4); // f4의 인자 4개를 모두 고정한 새로운함수
	f0(); //f4(1,2,3,4); --> 4항 함수를 0항 함수로 바꿈

	auto f2 = std::bind(&f4, 6, _1, 7, _2);
	f2(3, 9); // f4(6,3,7,9) 4항함수를 2항함수로

	auto f3 = std::bind(&f4, _2, _3, 8, _1);
	f3(9, 3, 7); // f4(3,7,8,9)

}