#include <iostream>

int add(int a, int b) {	return a + b; }

void foo( int(*f)(int, int) )
{
	int n = f(1,2);
}

int main()
{
	// #1. foo 의 인자로는 인자가 2개인 함수의 주소를 전달해야 합니다.
	//     => add 함수의 인자가 2개 이므로 아래 처럼 전달 가능합니다.
	foo(&add);

	// #2. "int add(int a, int b) {	return a + b; }" 에서 반환 타입과 함수이름을 제거하면
	//     "       (int a, int b) {	return a + b; }" 입니다.
	// foo 의 인자로 아래 처럼 전달 가능합니다.
	foo( [](int a, int b) {	return a + b; } );

	// 위처럼 함수의 주소를 전달하는 자리에 "함수의 구현 자체" 를 전달할수 있는 문법을 
	// "람다 표현식(lambda expression)" 이라고 합니다.

	// [] : 람다 표현식이 시작됨을 알리는 기호 입니다. lambda introducer 라고 합니다.
	
	// 람다 표현식 만드는 법
	// 1. 기존 함수 모양에서 "함수 반환 타입과 함수 이름을 제거합니다."
	// 2. 함수이름 위치에 [] 를 표기 합니다.

	// ex)
	// "int add(int a, int b) {	return a + b; }" 의미의 람다표현식은
	// "     [](int a, int b) {	return a + b; }" 입니다.
}