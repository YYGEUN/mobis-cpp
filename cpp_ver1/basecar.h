#pragma once
#include <iostream>

using namespace std;

class BaseCar {
protected:
	string _name;
	int _HP;
	int _Fuel;

public:
	BaseCar()
		:_HP(100), _Fuel(50)
	{
		_name = "�⺻��";
	}

	void setname(string name) {
		_name = name;
		//this->_name = name;
	}

	void output() {
		cout << "�̸� : " << _name << endl;
		cout << "���� : " << _HP << endl;
		cout << "���� : " << _Fuel << endl;
	}
};