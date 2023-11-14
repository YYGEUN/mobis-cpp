#include <iostream>

int main()
{
	int n = 10;

	int a = n; 	// n의 "값" 을 a 에 "복사" 합니다.
				// a 와 n 은 서로 다른 메모리를 사용하는 별도의 변수입니다.

	a = 30;		// a는 n과 별도의 변수 이므로 a 만 30이 되고, n 은 변경되지 않습니다.
	std::cout << n << std::endl; // 10

	//=====================
	int& r = n;	// r 은 n 의 alias(별명) 입니다.
	r = 30;		// r 은 n 의 별명이므로 이 코드는 n 자체가 변경된것입니다.
	std::cout << r << std::endl; // 30
}

