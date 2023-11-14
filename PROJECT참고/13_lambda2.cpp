#include <iostream>
#include <vector>
#include <algorithm>

// #1, #2, #3 순서로 주석 읽어 보세요

// #3.
// 단항함수 : 인자가 한개인 함수
// 조건자  : 반환 타입이 bool 인 함수(또는 bool 로 변환 가능한 것을 반환 하는 함수)

// foo : 인자로 전달된 값이 짝수 인지 조사하는 "단항 조건자(unary predicator)" 입니다.
bool foo(int n) { return n % 2 == 0;}

int main()
{
	std::vector<int> v = {1,4,3,2,5};

	// #1. 
	// std::find    : 주어진 구간에서 특정 값을 검색 합니다. 3번째 인자가 값 입니다.
	// std::find_if : 주어진 구간에서 특정 조건을 만족하는 요소를 검색 합니다. 3번째 인자가 단항함수(인자가 한개인 함수) 입니다.

	auto ret1 = std::find(   v.begin(), v.end(), 3);
	auto ret2 = std::find_if(v.begin(), v.end(), foo);
				// #2. 위 한줄의 의미
				// => v.begin() ~ v.end() 의 요소를 차례대로 foo 로 전달했을때
				//    foo 가 true 를 리턴하는 요소를 찾아라!
				//    따라서, foo 는 반환타입이 bool 이고 인자가 한개 인 함수 이어야 합니다.
				
}