#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

using namespace std;

//c언어 학습시 - 항상 메모리 그림을 그려서 생각합시다.
//c++ 학습시 - 항상 클래스 다이어그램(상속 관계 그림)을 그려서 생각합시다.



class BaseMenu
{
	string name;
public:
	BaseMenu(const string& s):name(s){}
	virtual ~BaseMenu() {}

	string getName() { return name; }
	
	virtual void command() = 0;

};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const string& m, int p) : BaseMenu(m), id(p) {}
	void command() override
	{
		cout << getName() << " 메뉴 선택됨\n";
		sleep(1);
	}
};

class PopupMenu : public BaseMenu
{
	vector<BaseMenu*> v;
public:
	PopupMenu(const string& s) : BaseMenu(s) {}
	void add(BaseMenu* m) {
		v.push_back(m);
	}
	void command() override
	{
		while (1) {
			system("cls"); // 화면 클리어

			for (auto m : v) {
				cout << m->getName() << endl;
			}
			cout << v.size() + 1 << ". 종료\n";

			int cmd;
			cout << "> 메뉴를 선택하세요 : ";
			cin >> cmd;

			if (cmd == v.size() + 1) { break; }

			if (cmd < 1 || cmd > v.size() + 1) {
				continue;
			}

			v[cmd - 1]->command();
		}
	}
};

int main()
{
	MenuItem m1("참치김밥", 11);
	MenuItem m2("소고기김밥", 12);
	MenuItem m3("참깨라면", 21);
	MenuItem m4("너구리라면", 22);
	MenuItem m5("진라면", 23);

	PopupMenu kimbab("김밥류");
	kimbab.add(&m1);
	kimbab.add(&m2);

	PopupMenu Ramen("라면류");
	Ramen.add(&m3);
	Ramen.add(&m4);
	Ramen.add(&m5);

	//m1.command();
	PopupMenu pm("오늘의 점심메뉴");
	pm.add(&kimbab); // 에러가남
	// menu5에서 해결
	pm.add(&Ramen);

	pm.command();
}