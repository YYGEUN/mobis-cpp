#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

// 객체지향 언어에서 프로그램이란 !!

// 1. 객체를 만들고
// 2. 객체간의 관계를 설정하고
// 3. 객체간의 메세지를 주고 받는 개념이다.(멤버 함수를 호출한다는 의미)
// 4. 프로그램의 기본 단위는 "함수" 가 아닌 "클래스" 이다

// 장점 : 확장성이 뛰어나고, 변화에 대응하기 좋다.!!

// 단점 : 어렵다!!
//       메모리 사용량이 많아 질수 있다.
//       (사용하지 않은 멤버가 메모리에 놓일수 있고 가상함수의 오버헤드도 있다)



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

