#pragma once
#include "basecar.h"

class avante
	:public BaseCar
{
public:
	virtual void output() {
		cout << "이름 : " << _name << endl;
		cout << "마력 : " << _HP << endl;
		cout << "연료 : " << _Fuel << endl;
	}

	void func() {
		cout << "제네시스?" << endl;
	}
};