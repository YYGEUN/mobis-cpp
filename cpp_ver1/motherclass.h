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
		cout << "부모 클래스 생성" << endl;
	}
	
	virtual ~motherclass() {
		cout << "부모 클래스 소멸" << endl;
	}

	int _freemoney = 5000;

	void output() {
		cout << "비상금 : " << _Megg <<endl;
		cout << "저축금 : " << _familyMoney << endl;
		cout << "생활비 : " << _livingMoney <<endl;
		cout << "꽁돈 : " << _freemoney <<endl;

	}
};
