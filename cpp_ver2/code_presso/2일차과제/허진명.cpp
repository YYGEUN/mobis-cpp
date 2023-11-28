#include <iostream>

using namespace std;

class Info {
private:
	string name;
	int age;
	string addr;
public:
	void setName(string name) { this->name = name; }
	void setAddr(string addr) { this->addr = addr; }
	void setAge(int age) { this->age = age; }

	string getName() { return name; }
	string getAddr() { return addr; }
	int getAge() { return age; }
};

Info* inputData(int &num) {
	string name;
	string addr;
	int age;
	cout << "1. �Է�" << endl;
	cout << "�� ���� �����͸� �Է��Ͻðڽ��ϱ�? : ";
	cin >> num;

	Info* ptr = new Info[num];

	for (int i = 0; i < num; i++) {
		cout << "\n�̸� : ";
		cin >> name;
		cout << "���� : ";
		cin >> age;
		cout << "�ּ� : ";
		cin >> addr;
		ptr[i].setName(name);
		ptr[i].setAge(age);
		ptr[i].setAddr(addr);
	}

	cout << "�Է��� ����Ǹ� ���� �޴���" << endl << endl; 
	return ptr;
}

//Info* memCopy(Info* prevInfo, int& prevNum, Info* newInfo, int& newNum) {
//	Info* ptr = new Info[prevNum + newNum];
//
//	for (int i = 0; i < prevNum + newNum; i++) {
//		if (i < prevNum) ptr[i] = prevInfo[i];
//		else ptr[i] = newInfo[i];
//	}
//
//	delete[] prevInfo;
//	delete[] newInfo;
//	prevInfo = NULL;
//	newInfo = NULL;
//
//	prevNum += newNum;
//	return ptr;
//}

void printData(Info* ptr, int& num) {
	if (ptr == NULL) {
		cout << "���� �Է� �� �޴� ��� �ٶ��ϴ�" << endl << endl;
		return;
	}
	cout << "2. ���" << endl;
	cout << "---------------------------------" << endl;
	cout << "      �̸�     ����     �ּ�      " << endl;
	cout << "---------------------------------" << endl;
	for (int i = 0; i < num; i++) {
		cout.width(11);
		cout << ptr[i].getName();
		cout.width(7);
		cout << ptr[i].getAge();
		cout.width(11);
		cout << ptr[i].getAddr() << endl;
	}
	cout << endl;
}

int main() {
	Info* ptr = NULL;
	int menuNum;
	int num;
	bool exitFlag = false;
	while (true) {
		cout << "���� �޴�)" << endl;
		cout << "		1. �Է�" << endl;
		cout << "		2. ���" << endl;
		cout << "		3. ����" << endl;
		cout << "		��ȣ�� �Է��ϼ��� : ";
		cin >> menuNum;

		switch (menuNum) {
		case 1: { ptr = inputData(num); break; }
		/*	Info* tempInfo;
			int tempNum; 
			tempInfo = inputData(tempNum);
			if (ptr == NULL) {
				ptr = tempInfo;
				num = tempNum;
			}
			else ptr = memCopy(ptr, num, tempInfo, tempNum);
			break; 
		}*/
		case 2: {printData(ptr, num); break; }
		case 3: {exitFlag = true; break; }
		default: {cout << "�Է� ���� �ʰ�" << endl; break; }
		}
		if (exitFlag) break;
	}
	if (ptr != NULL) delete[] ptr;

	return 0;
}