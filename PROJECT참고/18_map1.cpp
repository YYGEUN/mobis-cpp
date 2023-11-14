#include <map>
#include <iostream>
#include <string>

// map 을 이해하려면 std::pair 를 먼저 알아야 합니다
// std::pair : "서로 다른 타입의 값"을 2개 보관할수 있는 구조체 템플릿
// 구현 원리 
template<typename T1, typename T2>
struct pair
{
	T1 first;
	T2 second;

	pair() : first(), second() {} // first, second 를 디폴트 값으로 초기화
	pair(const T1& first, const T2& second) : first(first), second(second){}
};

int main()
{
	pair<int, double> p(1, 3.4);

	// 각 요소의 접근은 first, second 로 하면 됩니다.
	std::cout << p.first  << std::endl; // 1
	std::cout << p.second << std::endl; // 3.4

	// 위 처럼 만들어진 pair 가 이미 C++ 표준에 있는 것 입니다.
	std::pair<int, double> p2(1, 3.4); 
	
	// 아래 코드는 문자열 2개를 보관하는 pair 입니다.
	std::pair<std::string, std::string> p3("mon", "월요일");
}