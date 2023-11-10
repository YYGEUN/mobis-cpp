// function1.cpp
#include <iostream>
#include <functional> 
using namespace std::place_holders;

void f4(int a, int b, int c, int d)
{
	// 변수를 여러개 출력할때는 cout 보다 printf 가 편리하긴 합니다!
	printf("f4 : %d, %d, %d, %d\n", a, b, c, d);
}
int main()
{
	f4(1,2,3,4);
}