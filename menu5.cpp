#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

// C언어 학습할때         : 항상 메모리 그림을 그려서 생각하세요
// C++(객체지향) 학습 할때 : 항상 클래스 다이어그램(상속관계 그림)을 그려서 생각 하세요


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& s) : title(s){}

	std::string get_title() { return title; }

	virtual ~BaseMenu() {}

	// BaseMenu 에서는 command 가 있다는 것만 알리고
	// 실제 구현은 각각의 메뉴에서!!
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
				// vector<BaseMenu*> 이므로 v[cmd-1] 은 BaseMenu* 입니다
				// 이 코드가 되려면 반드시 BaseMenu 에서 command 가 있어야 합니다.
				// 모든 파생 클래스의 공통의 특징은 반드시 기반 클래스에도 있어야 한다.!
		}
	}
};

int main()
{
	MenuItem m1("참치김밥",  11);
	MenuItem m2("소고기김밥", 12);
	MenuItem m3("라면", 21);

	PopupMenu kimbab("김밥류");
	kimbab.add(&m1);
	kimbab.add(&m2);


	PopupMenu pm("오늘의 점심 메뉴");
	pm.add( &kimbab ); 
	pm.add( &m3 );

	pm.command(); 
}

