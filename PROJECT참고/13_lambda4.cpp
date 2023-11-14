#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int k = 3;

	std::vector<int> v = {1,4,3,2,5};

	// #1. 주어진 구간에서 처음 나오는 "짝수(2의 배수)"를 찾고 싶다
	auto ret1 = std::find_if(v.begin(), v.end(), [](int n) { return n % 2 == 0;});


	// #2. 주어진 구간에서 처음 나오는 "k의 배수"를 찾고 싶다
	// => 람다 표현식안에서 "n % 2 == 0" 이 아니라
	// =>              "n % k == 0" 으로 만들어야 합니다.
	// => 람다 표현식 안에서 main 의 지역변수 k를 사용하렴 캡쳐 라는 것을 해야 합니다.
	auto ret2 = std::find_if(v.begin(), v.end(), [k](int n) { return n % k == 0;});

	// #3. 값 캡쳐 와 참조 캡쳐 : [k], [&k]
	auto ret3 = std::find_if(v.begin(), v.end(), [k](int n) { return n % k == 0;});
																// => 여기있는 k는 지역변수 k가 아닌
																//    지역변수 k의 복사본 k 입니다.

	auto ret4 = std::find_if(v.begin(), v.end(), [&k](int n) { return n % k == 0;});
																// => 여기있는 k는 지역변수 k의 
																//    복사본이 아닌 별명(참조) 입니다.
																//    여기서 k를 변경하면 원본도 변경됩니다.
}