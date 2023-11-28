#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

using namespace std;

//c��� �н��� - �׻� �޸� �׸��� �׷��� �����սô�.
//c++ �н��� - �׻� Ŭ���� ���̾�׷�(��� ���� �׸�)�� �׷��� �����սô�.



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
		cout << getName() << " �޴� ���õ�\n";
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
			system("cls"); // ȭ�� Ŭ����

			for (auto m : v) {
				cout << m->getName() << endl;
			}
			cout << v.size() + 1 << ". ����\n";

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
	MenuItem m4("�ʱ������", 22);
	MenuItem m5("�����", 23);

	PopupMenu kimbab("����");
	kimbab.add(&m1);
	kimbab.add(&m2);

	PopupMenu Ramen("����");
	Ramen.add(&m3);
	Ramen.add(&m4);
	Ramen.add(&m5);

	//m1.command();
	PopupMenu pm("������ ���ɸ޴�");
	pm.add(&kimbab); // ��������
	// menu5���� �ذ�
	pm.add(&Ramen);

	pm.command();
}