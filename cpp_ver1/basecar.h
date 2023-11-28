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
		_name = "기본형";
	}

	void setname(string name) {
		_name = name;
		//this->_name = name;
	}

	void output() {
		cout << "이름 : " << _name << endl;
		cout << "마력 : " << _HP << endl;
		cout << "연료 : " << _Fuel << endl;
	}
};