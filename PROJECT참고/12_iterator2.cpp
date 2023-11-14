#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> v = {1,2,3,4,5};

	// #1. vector, list 등 대부분의 STL container 는 반복자가 있습니다
	//     begin(), end() 멤버 함수로 꺼내면 됩니다.
	auto p1 = v.begin(); // 컨테이너의 1번째 요소를 가리킵니다.
	auto p2 = v.end();   // 컨테이너의 마지막 다음을 가리킵니다.(마지막 요소의 다음 주소))
						 // 마지막 요소가 아니라는 사실이 중요합니다.
						 // p2 를 "past the lase element" 라고 부릅니다.

	*p1 = 10; // 이 코드는 문제 없지만
//	*p2 = 10; // 이 코드는 절대 사용하면 안됩니다.

	// #2. p2(v.end() 로 얻는 반복자) 는 p1 을 이동할때 끝에 도달했는지 확인 하는 용도로만 사용해야 합니다.
	while( p1 != p2 )
	{
		std::cout << *p1 << std::endl;
		++p1;
	}

	// #3. STL 의 std::find 같은 함수를 사용할때는 항상 인자가 "반복자" 입니다.
	// v.begin() 위치 부터, "v.end()의 하나 앞까지" 검색 합니다.
	auto ret = std::find( v.begin(), v.end(), 3);

	// #4. std::find 반환 값은 
	//     검색 성공시 : 요소(3) 을 가리키는 반복자
	//     검샐 실패시 : v.end()를 가리키는 반복자
	if ( ret == v.end() )
	{
		std::cout << "검색실패" << std::endl;
	}
	else 
	{
		std::cout << "검색 성공 : " << *ret << std::endl;
	}
}
