#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

class motherclass {
private:
	int _Megg = 100;

protected:
	int _familyMoney = 30000;
	int _livingMoney = 10000;

public:
	motherclass() {
		cout << "�θ� Ŭ���� ����" << endl;
	}
	
	virtual ~motherclass() {
		cout << "�θ� Ŭ���� �Ҹ�" << endl;
	}

	int _freemoney = 5000;

	void output() {
		cout << "���� : " << _Megg <<endl;
		cout << "����� : " << _familyMoney << endl;
		cout << "��Ȱ�� : " << _livingMoney <<endl;
		cout << "�ǵ� : " << _freemoney <<endl;

	}
};
