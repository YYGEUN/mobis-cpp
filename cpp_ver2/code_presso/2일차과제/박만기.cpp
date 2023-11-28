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
		 
			printf("이름 : ");
			cin >> name;
			cout << endl;
			printf("나이 : ");
			cin >> age;
			cout << endl;
			printf("주소 : ");
			cin >> adr;
			cout << endl;
		
	}


	void print() {
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
		cout << "주소 : " << adr << endl;
	}


};




void main() {

	address* people = new address[20];
	int cnt = 0;
	int flag = 0;
	int num = 0;
	while (true) {
		
		printf("1. 입력\n2. 출력\n3. 종료\n번호를 입력하세요 : ");
		cin >> num;
		switch (num)
		{
		case 1:
			
			printf("몇개의 데이터를 입력하시겠습니까?");
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