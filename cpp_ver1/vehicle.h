#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

class Vehicle
{
public:
	virtual void Boarding() {
		cout << "Å¾½Â" << endl;
	}
	virtual void Landing() {
		cout << "ÇÏÂ÷" << endl;
	}
	virtual void nothing() {
		cout << "-----" << endl;
	}
};