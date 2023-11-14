#include <iostream>

int main()
{
	int n = 0;

	while(1)
	{
		std::cin >> n; // 'aaa' 를 입력해 보세요

		if ( std::cin.fail() ) 
		{
			std::cout << "잘못입력했습니다. 다시 입력하세요\n";
			continue;
		}
		else
		{ 
			std::cout << "입력성공. 루프 탈출 합니다.\n";
			break;
		}
	}
	// 위 코드는 잘못 입력한 경우. 다시 입력 받는 것이 아니라 무한 루프에 빠지게 됩니다.
	// 이유는 
	// 1. std::cin 과 scanf 는 입력 버퍼라는 곳 에서 값을 꺼내오게 됩니다.

	// 2. 그런데, 초기에 입력 버퍼가 비어 있어서, "사용자로 부터 입력 버퍼에 입력 받는 내부루틴이 실행됩니다."
	
	// 3. 여러분이 "aaa" 를 입력하면 아래 처럼 놓이게 됩니다.
	//    입력버퍼 : "aaa"
	
	// 4. std::cin >> n 하는 순간 입력 버퍼에서 정수를 꺼내야 하는데, 정수가 없고 문자열이 있으므로 실패입니다.
	//    => 이때 핵심은 문자열이 계속 입력 버퍼에 남아 있다는 점입니다.

	// 5. 그래서 반복문의 처음으로 올라가서 다시 입려 받으려고 할때("std::cin >> n")
	//    => 입력버퍼 : "aaa"  인 상태이므로 계속 실패 입니다.

	// 결론 : 다시 입력 받으려면 입력 버퍼를 비워야 합니다.(다음소스 참고)
}