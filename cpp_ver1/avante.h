#pragma once
#include "basecar.h"

class avante
	:public BaseCar
{
public:
	virtual void output() {
		cout << "�̸� : " << _name << endl;
		cout << "���� : " << _HP << endl;
		cout << "���� : " << _Fuel << endl;
	}

	void func() {
		cout << "���׽ý�?" << endl;
	}
};