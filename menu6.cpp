#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s){}

	std::string get_title() { return title; }

	virtual ~BaseMenu() {}
	virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& s, int n) : BaseMenu(s), id(n) {}

	void command()
	{
		std::cout << get_title() << " 메뉴가 선택됨\n";

		getch(); 
	}
};

class PopupMenu : public BaseMenu
{

	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}

	void add(BaseMenu* p) { v.push_back(p); } 

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
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상 변경");
	PopupMenu* pm2 = new PopupMenu("해상도 변경");

	root->add(pm1);
	root->add(pm2);

	pm1->add( new MenuItem("RED",  11));
	pm1->add( new MenuItem("BLUE", 12));

	pm2->add( new MenuItem("HD",  21));
	pm2->add( new MenuItem("FHD", 22));

	// 이제 메뉴를 시작하려면 ?
}

