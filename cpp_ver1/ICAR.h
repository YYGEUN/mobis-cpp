#pragma once
#include<iostream>

using namespace std;

class ICAR
{
protected:
	int _Fuel;
	string _Type;
	
public:
	virtual ~ICAR() { };
	virtual void Info(string type,int num) = 0;
	virtual void Active() abstract;
	virtual void ReadFuel() = 0;
	virtual void InjectFuel(int num) = 0;
};