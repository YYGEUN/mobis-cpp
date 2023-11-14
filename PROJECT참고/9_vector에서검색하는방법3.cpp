#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8};

	// std::find    : 주어진 구간에서 3을 검색 합니다.
	// std::find_if : 주어진 구간에서 특정 조건을 만족하는 것을 검색 합니다.
	//				  3번째 인자로 값이 아닌 단항함수(인자가 한개인 함수)를 전달합니다.
	//				  람다표현식을 사용하면 됩니다.
	auto p1 = std::find(v.begin(), v.end(), 3); // 값(3) 검색

	auto p2 = std::find(v.begin(), v.end(), 
						[](int n) { return n % 2 == 0;}); // 짝수 검색!!

	std::cout << *p2 << std::endl; // 2
}