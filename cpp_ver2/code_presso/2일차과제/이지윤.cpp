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
		cout << "이름 : ";
		cin >> _name;
		name = _name;
	}
	void setAge() {
		int _age;
		cout << "나이 : ";
		cin >> _age;
		age = _age;
	}
	void setAddress() {
		string _address;
		cout << "주소 : ";
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
			cout << "1. 입력" << endl;
			cout << "2. 출력" << endl;
			cout << "3. 종료" << endl;
			cout << "번호를 입력하세요 : ";
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
		cout << "몇개의 데이터를 입력하시겠습니까? (1~3 사이의 정수 입력)" << endl;
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
		cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
		cout << "이름\t나이\t주소" << endl;
		cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
		for (int i = 0; i < humanCnt; i++) {
			humanPtr[i].getInfo();
		}
	}

};

int main() {
	AddresBook ab;

	return 0;
}

