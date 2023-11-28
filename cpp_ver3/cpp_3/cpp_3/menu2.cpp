#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#pragma warning(disable : 4996)

// 객체 지향 프로그래밍의 핵심
// --> 프로그램에서 필요한 타입을 먼저 설계

using namespace std;

class MenuItem
{
	string name;
	int id;
public:
	MenuItem(const string& m,int p) : name(m),id(p) {}
	string getName() { return name; }
	void command()
	{
		cout << getName() << " 메뉴 선택됨\n";
		getch();
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command();
}