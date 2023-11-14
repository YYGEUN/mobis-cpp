#include <map>
#include <string>
#include <iostream>

int main()
{
	std::map<std::string, std::string> m;

	m["mon"] = "월요일";
	m["tue"] = "화요일";

	// 특정 키값에 해당하는 value 를 구하고 싶다
	
	auto value = m["mon"]; // "mon" 키값이 있다면 "월요일" 이 나오지만
						   // 없다면 ("mon", "") 항목이 생성되고
						   // value 에 "" 가 반환 됩니다. 
						   // 결국 "mon" 키값이 생성된것

	auto p = m.find("tue"); 
			// => 키값이 있다면 해당 요소를 가리키는 반복자 반환
			// => 키값이 없다면 m.end() 와 같은 반복자 반환
			// => 키값이 없을때 키값을 만드는 것은 아님.
	
	if ( p == m.end() )
	{
		std::cout << "key 없음" << std::endl;
	}
	else 
	{
		// map 의 반복자에 대해서
		// map 의 요소 : std::pair
		// 반복자      : 요소를 가리크는 포인터 역활
		// 따라서 map 의 반복자 : std::pair 포인터 라고 생각하면 됩니다.
 
		std::cout << p->first  << std::endl; // 키값이므로 "tue"
		std::cout << p->second << std::endl; // value 이므로 "화요일"
	}

}