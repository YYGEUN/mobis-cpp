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
			cout << "메인 메뉴)" << endl;
			cout << "1.입력" << endl;
			cout << "2.출력" << endl;
			cout << "3.종료" << endl;
			cout << "번호를 입력하세요 :";
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
			cout << "몇개의 데이터를 입력하시겠습니까?" << endl;
			cin >> listNum;
			for (int i = 0; i < listNum; i++)
			{
				list[i] = new Address;
				string imsiName;
				int imsiage;
				string imsiaddress;
				cout << i+1<<" 번째 이름을 입력하세요:";
				cin >> imsiName;
				cout <<i+1<< "번째 나이를 입력하세요:";
				cin >> imsiage;
				cout << i+1<<"번째 주소를 입력하세요:";
				cin >> imsiaddress;

				list[i]->setInfo(imsiName, imsiage, imsiaddress);
			}

			break;
		case 2:
			cout << "-------------------------" << endl;
			cout << " 이름    나이     주소   " << endl;
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
			cout << "=====종    료======" << endl;
			return 0;
		default:
			break;
		}
		
	}

	return 0;
}