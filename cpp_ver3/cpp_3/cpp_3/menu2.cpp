#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#pragma warning(disable : 4996)

// ��ü ���� ���α׷����� �ٽ�
// --> ���α׷����� �ʿ��� Ÿ���� ���� ����

using namespace std;

class MenuItem
{
	string name;
	int id;
public:
	MenuItem(const string& m,int p) : name(m),id(p) {}
	string getName() { return name; }
	void command()
	{
		cout << getName() << " �޴� ���õ�\n";
		getch();
	}
};

int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);

	m1.command();
}