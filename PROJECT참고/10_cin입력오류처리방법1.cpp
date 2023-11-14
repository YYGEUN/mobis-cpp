#include <iostream>

int main()
{
	int n = 0;

	std::cin >> n; // 'a' 를 입력해 보세요
				   // 정수를 입력 받으려고 했는데, 문자를 입력했으므로
				   // 실패 입니다
	
	// std::cin 이라는 것은 미리 만들어져 있는 "객체" 입니다.
	// 따라서 멤버 함수가 있습니다.
	if ( std::cin.fail() )
		std::cout << "입력 실패" << std::endl;
	else 
		std::cout << "입력 성공" << std::endl;
	
	// 입력에 실패시 다시 입력 받아야 합니다. 
	// 다음 cin2.cpp 참고
}