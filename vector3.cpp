// vector2.cpp
#include <iostream>

int main()
{
	int cnt = 0;

	std::cout << "학생이 몇명인가요 >> ";
	std::cin >> cnt;

	// 입력된 학생수 만큼 다시 점수를 입력받고 싶다.
//	int score[cnt]; // error. 배열의 크기로 변수를 사용할수 없다.

	// 실행시간에 결정된 크기 만큼 메모리 할당을 하는 방법은
	// => 동적 메모리 할당 밖에 없습니다.
	// => malloc, new

	int* score = new int[cnt]; // ok. 변수 사용 가능

	for( int i = 0; i < 10; i++)
	{
		std::cin >> score[i]; // 포인터 이지만 배열 처럼 사용 가능
	}

	delete[] score; // 더이상 필요 없을때 반드시 delete 필요!
}








