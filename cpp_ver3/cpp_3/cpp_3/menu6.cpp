#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#pragma warning(disable : 4996)

using namespace std;

// 객체 지향 언어에서 프로그램이란
//
// 1.객체를 만듬
// 2.객체간의 관계 설정
// 3.객체간의 메세지를 주고받는 개념 (멤버함수를 호출한다는의미)
// 4.프로그램의 기본단위는 "함수" 가 아닌 "클래스"
// 
// 장점 : 확장성이 좋음, 변화대응하기 좋음
// 
// 단점 : 코드가 복잡(이해가 어려움)
//		  메모리 사용량이 많아 질 수 있다.
//		  (사용하지않은 멤버가 메모리에 놓일수있음 + 가상함수의 오버헤드
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
		cout << getName() << " 메뉴 선택됨\n";
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
			system("cls"); // 화면 클리어

			for (int i = 0; i < v.size();i++) {
				cout << i+1 << ". " << v[i]->getName() << endl;
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
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상 변경");
	PopupMenu* pm2 = new PopupMenu("해상도 변경");

	root->add(pm1);
	root->add(pm2);
	pm1->add(pm2);

	pm1->add(new MenuItem("RED", 11));
	pm1->add(new MenuItem("GREEN", 12));
	pm1->add(new MenuItem("BLUE", 13));

	pm2->add(new MenuItem("FHD", 21));
	pm2->add(new MenuItem("UHD", 22));

	root->command();

	//MenuItem m1("참치김밥", 11);
	//MenuItem m2("소고기김밥", 12);
	//MenuItem m3("참깨라면", 21);
	//MenuItem m4("너구리라면", 22);
	//MenuItem m5("진라면", 23);

	//PopupMenu kimbab("김밥류");
	//kimbab.add(&m1);
	//kimbab.add(&m2);

	//PopupMenu Ramen("라면류");
	//Ramen.add(&m3);
	//Ramen.add(&m4);
	//Ramen.add(&m5);

	////m1.command();
	//PopupMenu pm("오늘의 점심메뉴");
	//pm.add(&kimbab); // 에러가남
	//// menu5에서 해결
	//pm.add(&Ramen);

	//pm.command();
	cout << "나왔음" << endl;
	return 0;
}