#include <iostream>
#define MAX_ADDRESS_SIZE 10

using namespace std;

class Human {
private:
	string name;
	int age;
	string address;

public:
	Human() {
		name = "";
		age = 0;
		address = "";
	}
	~Human() {}

	void setName() {
		string _name;
		cout << "�̸� : ";
		cin >> _name;
		name = _name;
	}
	void setAge() {
		int _age;
		cout << "���� : ";
		cin >> _age;
		age = _age;
	}
	void setAddress() {
		string _address;
		cout << "�ּ� : ";
		cin >> _address;
		address = _address;
	}

	void getInfo() {
		cout << name << "\t" << age << "\t" << address << endl;
	}
};

class AddresBook {
private:
	Human* humanPtr;
	int humanCnt;

public:
	AddresBook() {
		humanPtr = new Human[MAX_ADDRESS_SIZE];
		humanCnt = 0;
		mainPage();
	}
	~AddresBook() {
		delete[] humanPtr;
	}

	void mainPage() {
		int num = 0;
		while (num != 3) {
			cout << "1. �Է�" << endl;
			cout << "2. ���" << endl;
			cout << "3. ����" << endl;
			cout << "��ȣ�� �Է��ϼ��� : ";
			cin >> num;

			switch (num)
			{
			case 1:
				inputPage();
				break;
			case 2:
				outputPage();
				break;
			case 3:
				break;
			default:
				break;
			}
		}
	}

	void inputPage() {
		int num = 0;
		cout << "��� �����͸� �Է��Ͻðڽ��ϱ�? (1~3 ������ ���� �Է�)" << endl;
		cin >> num;
		
		switch (num)
		{
		case 1:
			humanPtr[humanCnt].setName();
			humanCnt++;
			break;
		case 2:
			humanPtr[humanCnt].setName();
			humanPtr[humanCnt].setAge();
			humanCnt++;
			break;
		case 3:
			humanPtr[humanCnt].setName();
			humanPtr[humanCnt].setAge();
			humanPtr[humanCnt].setAddress();
			humanCnt++;
			break;
		default:
			break;
		}
	}

	void outputPage() {
		cout << "��������������������������������������������������������" << endl;
		cout << "�̸�\t����\t�ּ�" << endl;
		cout << "��������������������������������������������������������" << endl;
		for (int i = 0; i < humanCnt; i++) {
			humanPtr[i].getInfo();
		}
	}

};

int main() {
	AddresBook ab;

	return 0;
}

