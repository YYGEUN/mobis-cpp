#include <map>
#include <string>
#include <vector>
#include <iostream>

// 아래 코드를 보고 "std::map" 의 개념과 사용법을 익히세요

int main()
{
	// #1. map 은 key 값으로 value 를 보관합니다.
	// key 도 문자열, value 도 문자열
	std::map<std::string, std::string> m1; 
	m1["mon"] = "월요일";

	std::string s = m1["mon"]; 	// s 는 "월요일" 입니다.
								// 마치 영한 사전 처럼 보입니다.
								// 그래서 map 을 다른 언어에서는 "dictionary"
								// 라고도 합니다.

	// #2. 아래 코드는 문자열을 키값으로 std::vector<string> 을 보관합니다. 입니다.
	std::map<std::string, std::vector<std::string>> m2;

	m2["홍길동"].push_back("추리소설");	// "m2[key]"" 하면 value 가 나오므로
									// "m2[key]" 는 vector<string> 입니다.
	m2["홍길동"].push_back("SF소설");
	m2["홍길동"].push_back("영어소설");

	// 위 코드는 결국 "홍길동" 이라는 사람이 3권의 서적을 빌려간 것을 나타냅니다.
	auto& v = m2["홍길동"]; // v 는 std::vector<std::string>
						  // v 안에는 "추리소설", "SF소설", "영어소설" 이 있습니다

	// 아래 코드를 실행해 보세요
	for( auto& e : v)
	{
		std::cout << e << std::endl;
	}
									
	



}