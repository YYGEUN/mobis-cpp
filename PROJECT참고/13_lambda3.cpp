#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 2 == 0;}

int main()
{
	std::vector<int> v = {1,4,3,2,5};

	// #1. std::find_if 의 인자로 단항 조건자를 만들어서 전달해도 되지만
	//     동일한 의미의 람다 표현식을 사용하는 것이 편리합니다.
	//     람다 표현식이 좀더 빠르게 동작합니다.(이유는 복잡합니다. 중급이상의 과정에서 다루는 주제)
	auto ret1 = std::find_if(v.begin(), v.end(), foo);
	auto ret2 = std::find_if(v.begin(), v.end(), [](int n) { return n % 2 == 0;});
									// => foo 함수의 모양에서 "bool foo" 를 제거하고 "[]" 적으면 됩니다.				
}