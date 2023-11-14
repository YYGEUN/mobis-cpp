#include <iostream>

// 아래 3줄은 입력 버퍼의 최대 크기를 얻기 위한 코드 입니다.
#include <limits>
#include <sstream>
 
const unsigned long max_size = std::numeric_limits<std::streamsize>::max();

int main()
{
	int n = 0;

	while(1)
	{
		std::cin >> n; // 'aaa' 를 입력해 보세요

		if ( std::cin.fail() ) 
		{
			std::cout << "잘못입력했습니다. 다시 입력하세요\n";

			// 다시 입력 받을때 반드시 아래 코드가 필요 합니다.
			std::cin.clear(); 					// 1. 성공, 실패 여부를 관리하는 멤버를 reset 합니다.
			std::cin.ignore(max_size, '\n'); 	// 2. 입력 버퍼의 모든 내용을 제거합니다.
									// '\n' 를 찾을때까지 최대 max_size 만큼 제거해 달라는 의미

			// 이제 입력 버퍼를 완전히 지웠고, 성공 실패를 관리하는 멤버의 상태를 reset 했으므로
			// 다시 입력 받으면 됩니다.
			continue;
		}
		else
		{ 
			std::cout << "입력성공. 루프 탈출 합니다.\n";
			break;
		}
	}

}