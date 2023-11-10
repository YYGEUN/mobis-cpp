#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

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

		getch(); 
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& s) : title(s) {}

	void add(MenuItem* p) { v.push_back(p); } 

	void command()
	{
		while(1)
		{
			system("cls"); 

			int sz = v.size(); 
			for ( int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료\n";

			int cmd;
			std::cout << "메뉴를 선택하세요 >> ";
			std::cin >> cmd;

			if ( cmd == sz + 1) 
				break;

			if ( cmd < 1 || cmd > sz + 1 ) 
				continue;

			v[cmd-1]->command();
		}
	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	PopupMenu pm("오늘의 점심 메뉴");
	pm.add(&m1);
	pm.add(&m2);

	pm.command(); 
}

