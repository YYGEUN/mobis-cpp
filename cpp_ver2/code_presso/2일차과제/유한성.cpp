#include <stdio.h>
#include <iostream>

using namespace std;

class Address
{
private:
	string Name;
	int age;
	string address;
public:
	void setInfo(string name, int age, string address)
	{
		this->Name = name;
		this->age = age;
		this->address = address;
	}
	void printInfo()
	{
		cout << Name <<"       " << age <<"       " << address << endl;
	}

};

class Menu
{
private:
	static int selectNum;
public:
	static int menuscreen()
	{
			cout << "���� �޴�)" << endl;
			cout << "1.�Է�" << endl;
			cout << "2.���" << endl;
			cout << "3.����" << endl;
			cout << "��ȣ�� �Է��ϼ��� :";
			cin >> selectNum;
			return selectNum;
	}
};

int Menu::selectNum = 0;


int main()
{
	Address* list[20];
	int listNum = 0;
	while (1)
	{
		switch (Menu::menuscreen())
		{
		case 1:
			cout << "��� �����͸� �Է��Ͻðڽ��ϱ�?" << endl;
			cin >> listNum;
			for (int i = 0; i < listNum; i++)
			{
				list[i] = new Address;
				string imsiName;
				int imsiage;
				string imsiaddress;
				cout << i+1<<" ��° �̸��� �Է��ϼ���:";
				cin >> imsiName;
				cout <<i+1<< "��° ���̸� �Է��ϼ���:";
				cin >> imsiage;
				cout << i+1<<"��° �ּҸ� �Է��ϼ���:";
				cin >> imsiaddress;

				list[i]->setInfo(imsiName, imsiage, imsiaddress);
			}

			break;
		case 2:
			cout << "-------------------------" << endl;
			cout << " �̸�    ����     �ּ�   " << endl;
			cout << "-------------------------" << endl;

			for (int i = 0; i < listNum; i++)
			{
				list[i]->printInfo();
			}
	
			break;
		case 3:
			for (int i = 0; i < listNum; i++)
			{
				delete list[i];
			}
			cout << "=====��    ��======" << endl;
			return 0;
		default:
			break;
		}
		
	}

	return 0;
}