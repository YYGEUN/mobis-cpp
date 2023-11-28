#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#pragma warning(disable : 4996)

using namespace std;

// ��ü ���� ���� ���α׷��̶�
//
// 1.��ü�� ����
// 2.��ü���� ���� ����
// 3.��ü���� �޼����� �ְ�޴� ���� (����Լ��� ȣ���Ѵٴ��ǹ�)
// 4.���α׷��� �⺻������ "�Լ�" �� �ƴ� "Ŭ����"
// 
// ���� : Ȯ�强�� ����, ��ȭ�����ϱ� ����
// 
// ���� : �ڵ尡 ����(���ذ� �����)
//		  �޸� ��뷮�� ���� �� �� �ִ�.
//		  (����������� ����� �޸𸮿� ���ϼ����� + �����Լ��� �������
//


class BaseMenu
{
	string name;
public:
	BaseMenu(const string& s) :name(s) {}
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
		Sleep(1000);
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

			for (int i = 0; i < v.size();i++) {
				cout << i+1 << ". " << v[i]->getName() << endl;
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
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("���� ����");
	PopupMenu* pm2 = new PopupMenu("�ػ� ����");

	root->add(pm1);
	root->add(pm2);
	pm1->add(pm2);

	pm1->add(new MenuItem("RED", 11));
	pm1->add(new MenuItem("GREEN", 12));
	pm1->add(new MenuItem("BLUE", 13));

	pm2->add(new MenuItem("FHD", 21));
	pm2->add(new MenuItem("UHD", 22));

	root->command();

	//MenuItem m1("��ġ���", 11);
	//MenuItem m2("�Ұ����", 12);
	//MenuItem m3("�������", 21);
	//MenuItem m4("�ʱ������", 22);
	//MenuItem m5("�����", 23);

	//PopupMenu kimbab("����");
	//kimbab.add(&m1);
	//kimbab.add(&m2);

	//PopupMenu Ramen("����");
	//Ramen.add(&m3);
	//Ramen.add(&m4);
	//Ramen.add(&m5);

	////m1.command();
	//PopupMenu pm("������ ���ɸ޴�");
	//pm.add(&kimbab); // ��������
	//// menu5���� �ذ�
	//pm.add(&Ramen);

	//pm.command();
	cout << "������" << endl;
	return 0;
}