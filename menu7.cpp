#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <functional>
using namespace std::place_holders;


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s){}

	std::string get_title() { return title; }

	virtual ~BaseMenu() {}
	virtual void command() = 0;
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

class MenuItem : public BaseMenu
{
	int id;
	using HANDLER = std::function<void()>;

	HANDLER handler; // 메뉴 선택시 호출될 함수

public:
	MenuItem(const std::string& s, int n, HANDLER h = nullptr ) 
				: BaseMenu(s), id(n), handler(h) {}

	void command()
	{
		// 메뉴 선택시 등록된 함수 호출!
		if ( handler != nullptr )
			handler(); 
		
	}
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상 변경");
	PopupMenu* pm2 = new PopupMenu("해상도 변경");

	root->add(pm1);
//	root->add(pm2);
	pm1->add(pm2);


	pm1->add( new MenuItem("RED",  11));
	pm1->add( new MenuItem("BLUE", 12));
	pm1->add( new MenuItem("GREEN", 13));

	pm2->add( new MenuItem("HD",  21));
	pm2->add( new MenuItem("FHD", 22));

	// 이제 메뉴를 시작하려면 ?
	root->command();
}

