#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#pragma warning(disable : 4996)

using namespace std;

class MenuItem
{
	string name;
	int id;
public:
	MenuItem(const string& m, int p) : name(m), id(p) {}
	virtual ~MenuItem(){}
	string getName() { return name; }
	void command()
	{
		cout << getName() << " 메뉴 선택됨\n";
		getch();
	}
};

class PopupMenu
{
	string name;
	vector<MenuItem*> v;
public:
	PopupMenu(const string& s): name(s) {}
	void add(MenuItem* m) {
		v.push_back(m);
	}
	void command()
	{
		while (1) {
			system("cls"); // 화면 클리어

			for (auto m : v) {
				cout << m->getName() << endl;
			}
			cout << v.size() << ". 종료\n";
		
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
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	//m1.command();
	PopupMenu pm("오늘의 점심메뉴");
	pm.add(&m1);
	pm.add(&m2);

	pm.command();
}