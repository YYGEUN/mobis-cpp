#pragma warning (disable:4996)
#include "test.h"
#include <iostream>
using namespace std;

class address {
private:

	string name;
	int age;
	string adr;
public:

	void input() {
		 
			printf("�̸� : ");
			cin >> name;
			cout << endl;
			printf("���� : ");
			cin >> age;
			cout << endl;
			printf("�ּ� : ");
			cin >> adr;
			cout << endl;
		
	}


	void print() {
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
		cout << "�ּ� : " << adr << endl;
	}


};




void main() {

	address* people = new address[20];
	int cnt = 0;
	int flag = 0;
	int num = 0;
	while (true) {
		
		printf("1. �Է�\n2. ���\n3. ����\n��ȣ�� �Է��ϼ��� : ");
		cin >> num;
		switch (num)
		{
		case 1:
			
			printf("��� �����͸� �Է��Ͻðڽ��ϱ�?");
			scanf("%d", &cnt);
			for (int i = 0; i < cnt; i++) {
				people[i].input();
			}
			break;
		
		case 2:
			for (int i = 0; i < cnt; i++) {
				people[i].print();
			}
			break;

		case 3:
			delete[] people;
			flag = 1;
			break;
		}
		if (flag == 1) {
			break;
		}
	}
}