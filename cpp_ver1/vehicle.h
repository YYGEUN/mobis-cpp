#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

class Vehicle
{
public:
	virtual void Boarding() {
		cout << "ž��" << endl;
	}
	virtual void Landing() {
		cout << "����" << endl;
	}
	virtual void nothing() {
		cout << "-----" << endl;
	}
};