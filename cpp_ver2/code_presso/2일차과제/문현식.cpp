#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <iomanip>
using namespace std;

class Data {
private:
	int PersonNum = 0;
	int age[50];
	string city[50];
	string name[50];
public:
	void scanData(int cnt) {
		int nameCnt = 0;
		cout << "1. �Է�" << endl;
		cout << "�� ���� �����͸� �Է��Ͻðڽ��ϱ�?" << endl;
		cin >> nameCnt;
		for (int i = PersonNum; i < nameCnt+ PersonNum; i++) {
			cout << "�̸� :";
			cin >> name[i];
			cout << "���� :";
			cin >> age[i];
			cout << "�ּ� :";
			cin >> city[i];
			cout << endl;
		}
		PersonNum += nameCnt;
	}

	void showData(int cnt) {
		printf("�� ��� �ο� : %d��\n", PersonNum);
		printf("--------------------------------\n\n");
		printf("    �̸�      ����      �ּ�    \n\n");
		printf("--------------------------------\n\n");
		for(int i = 0; i < PersonNum; i++){
			cout << "   " << setw(4)<<  name[i] << "     " << setw(3) <<  age[i] << "     " << setw(4) << city[i] << "    " << endl;
		}
		printf("\n");
	}
};

class Menu {
private:
	int cnt=0;
public:
	void menuShow(){
		cout << "���� �޴�" << endl;
		cout << "1.�Է� \n2.��� \n3.����" << endl;
		cout << "��ȣ�� �Է��ϼ��� :";
	}

	int menuSelect() {
		cin >> cnt;
		return cnt;
	}
};

int main() {
	Menu menu;
	Data dataPerson;
	int menuNum = 0;
	int cntC = 0;
	while (1) {
		menu.menuShow();
		//���θ޴� â display
		menuNum = menu.menuSelect();
		
		if (menuNum == 3) {
			printf("�ý��� ���� \n\n");
			break;
		}

		switch (menuNum) {
		case 1:
			dataPerson.scanData(menuNum);
			break;
		case 2:
			dataPerson.showData(menuNum);
			break;
		}


	}

	return 0;
}