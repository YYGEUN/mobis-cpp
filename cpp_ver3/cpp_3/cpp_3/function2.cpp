#include <iostream>
#include <functional>
//#include <stdio.h>

using namespace std::placeholders;

void f4(int a, int b, int c, int d) {
	printf("f4 : %d, %d, %d, %d\n", a, b, c, d);
}

void f1(int a) {
	printf("f1 : %d\n", a);
}

void f2(int a, int b) {
	printf("f4 : %d, %d\n", a, b);
}

int main()
{
	f4(1, 2, 3, 4);

	//void(*f)(int) = &f1;
	//f(10); // f1(10);
	//f = &f2; //error 인자의 형태가 다름

	//STL의 std::function 이 함수 포인터보다 편리
	//사용법 : std::function<함수모양>

	std::function<void(int)> f;
	f = &f1;
	f(10); //f1(10)
	
	//f = &f2; //error
	// std::function 의 장점 -> std::bind의 반환값 보관 가능
	// 즉 2항함수 => 1항함수 로 변경해서 담으면된다
	f = std::bind(&f2,_1, 3);
	f(5); // f2(5,3)

	f = std::bind(&f4, 3, 6, _1, 9);
	f(5); // f4(3,6,5,9)

}