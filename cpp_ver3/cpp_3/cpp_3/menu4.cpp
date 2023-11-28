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
		cout << getName() << " �޴� ���õ�\n";
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
			system("cls"); // ȭ�� Ŭ����

			for (auto m : v) {
				cout << m->getName() << endl;
			}
			cout << v.size() << ". ����\n";

			int cmd;
			cout << "> �޴��� �����ϼ��� : ";
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
	MenuItem m1("��ġ���", 11);
	MenuItem m2("�Ұ����", 12);
	MenuItem m3("�������", 21);

	PopupMenu kimbab("����");
	kimbab.add(&m1);
	kimbab.add(&m2);

	//m1.command();
	PopupMenu pm("������ ���ɸ޴�");
	pm.add(&kimbab); // ��������
					 // menu5���� �ذ�
	pm.add(&m3);

	pm.command();
}