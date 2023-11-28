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
		cout << "1. 입력" << endl;
		cout << "몇 개의 데이터를 입력하시겠습니까?" << endl;
		cin >> nameCnt;
		for (int i = PersonNum; i < nameCnt+ PersonNum; i++) {
			cout << "이름 :";
			cin >> name[i];
			cout << "나이 :";
			cin >> age[i];
			cout << "주소 :";
			cin >> city[i];
			cout << endl;
		}
		PersonNum += nameCnt;
	}

	void showData(int cnt) {
		printf("총 등록 인원 : %d명\n", PersonNum);
		printf("--------------------------------\n\n");
		printf("    이름      나이      주소    \n\n");
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
		cout << "메인 메뉴" << endl;
		cout << "1.입력 \n2.출력 \n3.종료" << endl;
		cout << "번호를 입력하세요 :";
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
		//메인메뉴 창 display
		menuNum = menu.menuSelect();
		
		if (menuNum == 3) {
			printf("시스템 종료 \n\n");
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