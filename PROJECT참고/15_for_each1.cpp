#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v = {1,2,3,4,5};

	// #1. std::for_each : 주어진 구간의 모든 요소를 3번째 인자로 전달한 함수에 보내달라.
	//                     3번째 인자는 단항함수 이어야 합니다.
//	std::for_each(v.begin(), v.end(), 단항함수);


	// #2. 단항함수로 람다 표현식등을 사용하면 됩니다.
	//     결국 아래 코드는 모든 요소를 화면 출력하는 코드입니다.
	std::for_each(v.begin(), v.end(), [](int n) {std::cout << n << ", ";});
}