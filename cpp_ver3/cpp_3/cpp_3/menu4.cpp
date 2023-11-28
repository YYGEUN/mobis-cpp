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
	virtual ~MenuItem() {}
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
	PopupMenu(const string& s) : name(s) {}
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
	MenuItem m1("참치김밥", 11);
	MenuItem m2("소고기김밥", 12);
	MenuItem m3("참깨라면", 21);

	PopupMenu kimbab("김밥류");
	kimbab.add(&m1);
	kimbab.add(&m2);

	//m1.command();
	PopupMenu pm("오늘의 점심메뉴");
	pm.add(&kimbab); // 에러가남
					 // menu5에서 해결
	pm.add(&m3);

	pm.command();
}