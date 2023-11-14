#include <vector>
#include <iostream>
// 컨테이너의 모든 요소를 출력하는 함수
template<typename Cont>
void show(const Cont& c)
{
	for ( auto& e : c)
		std::cout << e << ", ";

	std::cout << '\n';
} 


int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

	//---------------------------------
	for(int e : v)  // v의 각 요소의 값을 차례대로 e에 "복사"합니다.
	{				// 즉, int e = v[0] 의 의미 입니다.
					// for ( auto e : v) 로 해도 동일합니다.

		e = 0;		// e 를 변경해도 v 의 요소가 변경되는 것은 아닙니다.
	}
	show(v);		// 1,2,3,4,5,6,7,8,9,10
	//---------------------------------
	for(int& e : v) // e 는 v의 각 요소를 가리키는 별명(alias) 입니다.
	{				// 즉, int& e = v[0] 의 의미 입니다.
					
		e = 0;		// e는 v 의 각 요소의 별명이므로 이 코드는 v 의 모든 요소를 0으로 만드는 코드입니다.
	}
	show(v);		// 0,0,0,0,0,0,0,0,0,0
	
}