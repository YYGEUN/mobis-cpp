#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <functional>
#include <memory>
using namespace std::placeholders;

// 금요일 배운 Menu7.cpp 를 스마트 포인터 버전으로 변경한 코드 입니다.
// BaseMenu*				==> std::shared_ptr<BaseMenu>
// PopupMenu*				==> std::shared_ptr<PopupMenu>
// MenuItem*				==> std::shared_ptr<MenuItem>
// new PopupMenu("색상변경")  ==> std::make_shared<PopupMenu>("색상변경");
// new MenuItem("HD", 11)	==> std::make_shared<MenuItem>("HD", 11);

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
	// 스마트 포인터 도입에 따른 변화 #1
//	std::vector<BaseMenu*> v;				  // 이 코드가
	std::vector<std::shared_ptr<BaseMenu>> v; // 이렇게 변경됩니다.
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}

	// 스마트 포인터 도입에 따른 변화 #2
//	void add(BaseMenu* p) { v.push_back(p); } 
	void add(std::shared_ptr<BaseMenu> p) { v.push_back(p); } 

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

	HANDLER handler; 

public:
	MenuItem(const std::string& s, int n, HANDLER h = nullptr ) 
				: BaseMenu(s), id(n), handler(h) {}

	void command()
	{
		if ( handler != nullptr )
			handler(); 
		
	}
};

void foo() { std::cout << "foo\n"; getch();}
void goo() { std::cout << "goo\n"; getch();}
void hoo(int id) 
{ std::cout << "hoo " << id << "\n"; getch();}

int main()
{
	// 스마트 포인터 도입에 따른 변화 #3. 
	/*
	// # 기존 코드
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상 변경");
	PopupMenu* pm2 = new PopupMenu("해상도 변경");

	root->add(pm1);
	root->add(pm2);

	pm1->add( new MenuItem("RED",  11, &foo));
	pm1->add( new MenuItem("BLUE", 12, &goo));
	pm1->add( new MenuItem("GREEN", 13));

	pm2->add( new MenuItem("HD",  21, std::bind(&hoo, 21) ));
	pm2->add( new MenuItem("FHD", 22, std::bind(&hoo, 22)));
	*/
	// # 새로 변경한 코드

	std::shared_ptr<PopupMenu> root = std::make_shared<PopupMenu>("ROOT");
	std::shared_ptr<PopupMenu> pm1 =  std::make_shared<PopupMenu>("색상 변경");
	std::shared_ptr<PopupMenu> pm2 =  std::make_shared<PopupMenu>("해상도 변경");

	root->add(pm1);
	root->add(pm2);

	pm1->add( std::make_shared<MenuItem>("RED",  11, &foo));
	pm1->add( std::make_shared<MenuItem>("BLUE", 12, &goo));
	pm1->add( std::make_shared<MenuItem>("GREEN", 13));

	pm2->add( std::make_shared<MenuItem>("HD",  21, std::bind(&hoo, 21) ));
	pm2->add( std::make_shared<MenuItem>("FHD", 22, std::bind(&hoo, 22)));

	
	root->command();
}

