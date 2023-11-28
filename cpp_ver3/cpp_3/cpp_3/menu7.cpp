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
	using HANDLER2 = std::function<void(int,int)>; // 두개 함수도 받을수있음 --> 더많으면 바인드 // 더작은건불가
	HANDLER handler; // 메뉴선택시 호출될 함수
	//HANDLER2 handler2;
public:
	MenuItem(const std::string& m, int p, HANDLER h = nullptr) : BaseMenu(m), id(p),handler(h) {} // 핸들러를 등록하지않으면 nullptr
	//MenuItem(const std::string& m, int p, HANDLER2 h = nullptr) : BaseMenu(m), id(p), handler2(h) {} // 핸들러를 등록하지않으면 nullptr
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
			system("cls"); // 화면 클리어

			for (int i = 0; i < v.size(); i++) {
				std::cout << i + 1 << ". " << v[i]->getName() << std::endl;
			}
			std::cout << v.size() + 1 << ". 종료\n";

			int cmd;
			std::cout << "> 메뉴를 선택하세요 : ";
			std::cin >> cmd;

			if (cmd == v.size() + 1) { break; }

			if (cmd < 1 || cmd >= v.size() + 1) {
				continue;
			}

			v[cmd - 1]->command();
		}
	}
};

//메뉴 선택시 수행될 함수를 만들어 메뉴에 등록하세요
void foo() { std::cout << "foo\n"; Sleep(2000); }
void goo() { std::cout << "goo\n"; Sleep(2000); }
void hoo(int id) { std::cout << "hoo "<< id << std::endl; Sleep(2000); }
void test(int a, int b) { std::cout << a << "   " << b; }

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상 변경");
	PopupMenu* pm2 = new PopupMenu("해상도 변경");

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

	std::cout << "나왔음" << std::endl;
	return 0;
}