// menu1.cpp
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>


// 객체지향 프로그래밍의 핵심
// => 프로그램에서 필요한 "타입" 을 먼저 설계하는 것!!

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& s, int n) : title(s), id(n) {}

	std::string get_title() { return title; }

	void command()
	{
		std::cout << get_title() << " 메뉴가 선택됨\n";
		
		getch(); // 끝나지 말고 잠시대기(테스트용)
	}
};


int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command(); // 메뉴를 선택하면 이 함수를 호출!
}