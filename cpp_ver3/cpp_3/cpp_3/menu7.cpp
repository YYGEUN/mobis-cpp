#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <functional>
#pragma warning(disable : 4996)

using namespace std::placeholders;

class BaseMenu
{
	std::string name;
public:
	BaseMenu(const std::string& s) :name(s) {}
	virtual ~BaseMenu() {}

	std::string getName() { return name; }

	virtual void command() = 0;

};

class MenuItem : public BaseMenu
{
	int id;
	using HANDLER = std::function<void()>;
	using HANDLER2 = std::function<void(int,int)>; // �ΰ� �Լ��� ���������� --> �������� ���ε� // �������ǺҰ�
	HANDLER handler; // �޴����ý� ȣ��� �Լ�
	//HANDLER2 handler2;
public:
	MenuItem(const std::string& m, int p, HANDLER h = nullptr) : BaseMenu(m), id(p),handler(h) {} // �ڵ鷯�� ������������� nullptr
	//MenuItem(const std::string& m, int p, HANDLER2 h = nullptr) : BaseMenu(m), id(p), handler2(h) {} // �ڵ鷯�� ������������� nullptr
	void command() override
	{
		if (handler != nullptr) {
			handler();
		}
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& s) : BaseMenu(s) {}
	void add(BaseMenu* m) {
		v.push_back(m);
	}
	void command() override
	{
		while (1) {
			system("cls"); // ȭ�� Ŭ����

			for (int i = 0; i < v.size(); i++) {
				std::cout << i + 1 << ". " << v[i]->getName() << std::endl;
			}
			std::cout << v.size() + 1 << ". ����\n";

			int cmd;
			std::cout << "> �޴��� �����ϼ��� : ";
			std::cin >> cmd;

			if (cmd == v.size() + 1) { break; }

			if (cmd < 1 || cmd >= v.size() + 1) {
				continue;
			}

			v[cmd - 1]->command();
		}
	}
};

//�޴� ���ý� ����� �Լ��� ����� �޴��� ����ϼ���
void foo() { std::cout << "foo\n"; Sleep(2000); }
void goo() { std::cout << "goo\n"; Sleep(2000); }
void hoo(int id) { std::cout << "hoo "<< id << std::endl; Sleep(2000); }
void test(int a, int b) { std::cout << a << "   " << b; }

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("���� ����");
	PopupMenu* pm2 = new PopupMenu("�ػ� ����");

	root->add(pm1);
	root->add(pm2);
	pm1->add(pm2);

	pm1->add(new MenuItem("RED", 11,&foo));
	pm1->add(new MenuItem("GREEN", 12,&foo));
	pm1->add(new MenuItem("BLUE", 13,&goo));
	//pm1->add(new MenuItem("WHITE", 14, &test(4,3));

	pm2->add(new MenuItem("FHD", 21,std::bind(&hoo,21)));
	pm2->add(new MenuItem("UHD", 22, std::bind(&hoo,22)));

	root->command();

	std::cout << "������" << std::endl;
	return 0;
}