// vector2.cpp
#include <iostream>

int main()
{
	// 사용자에게 정수 10개를 입력받아 보세요 - std::cin 사용하세요
	// 입력된 10개의 정수는 나중에 사용하기 위해 반드시 보관 하고 있어야 합니다.
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10; // 방법1. 10개의 서로 다른 이름을 가진 변수

	int x[10] = {0}; // 10개의 변수가 "한개의 이름+인덱스" 로 사용
		       		// 반복문에서 사용가능

	for( int i = 0; i < 10; i++)
	{
		std::cin >> x[i];
	}
}





