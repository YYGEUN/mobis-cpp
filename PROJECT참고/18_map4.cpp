#include <map>
#include <string>
#include <iostream>

int main()
{
	std::map<std::string, std::string> m;

	m["mon"] = "월요일";
	m["tue"] = "화요일";

	// map 과 range-for

	// #1.
	for( auto e : m )	
	{
		// 1. map 의 요소는 std::pair 이므로 e 는 std::pair 입니다.
		std::cout << e.first << std::endl; // "mon", "tue"
		std::cout << e.second << std::endl; // "월요일", "화요일"

		// 2. "auto e : m" 이므로 e 는 map 에 있는 요소를 복사 했으므로
		//    아래 코드는 map 자체가 변경되지 않습니다.
		e.second = "수요일"; // 복사본 e 만 변경. map 자체 변경은 안됨

		// 3. 또한 "auto e : m" 의 코드는 
		//    "문자열 2개를 보관하는 pair" 이 복사본이 생성되므로 성능상 아주 나쁜 코드입니다.
	}

	// map 의 요소를 range-for 하려면 아래 처럼 하세요
	// # 읽기만 한다면
	for( const auto& e : m )
	{
		// 여기서 e.first, e.second 로 사용
	}

	// # 변경하기도 한다면 "const" 제거하세요
	for( auto& e : m )
	{
		e.second = "일요일"; // ok. map 자체도 변경된
	//	e.first = "sun"; // error. map 의 키값은 const 로 저장됩니다. 절대 변경안됩니다.
	}

	//---------
	// 단, int, int 등을 보관하는 map 의 요소는 pair<int, int> 이므로 
	// 크기가 크지 않으면 value 로 해도 나쁘지 않습니다.
	std::map<int, int> m2;

	m2[0] = 1;

	for( auto e : m2)  // 모든 요소에 대해서 복사본 pair 를 만들지만
	{					// 나쁘지 않은 코드 입니다.
	}

}