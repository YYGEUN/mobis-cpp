#include "Energy.h"

void UseEnergy::Info(string type, int num)
{
	UseEnergy::_Type = type;
	UseEnergy::_Fuel = num;
}

void UseEnergy::Active()
{
	if (UseEnergy::_Fuel != 0) {
		cout << UseEnergy::_Type << " Driving ON\n";
	}
	else {
		cout << UseEnergy::_Type << " 연료 없음\n";
	}
}

void UseEnergy::InjectFuel(int num)
{
	UseEnergy::_Fuel += num;
}

void UseEnergy::ReadFuel()
{
	cout << "현재 잔여량 : " << UseEnergy::_Fuel << endl;
}

void menu(ICAR* icar) {
	int n = 0;
	string name;
	int num = 0;

	cout << "1. setting info\n" << "2. Active\n" << "3. inject\n" << "4. Read Fuel\n";
	cin >> n;
	switch (n)
	{
	case 1:
		cout << "연료 타입 : ";
		cin >> name;
		cout << "연료량 : ";
		cin >> num;
		icar->Info(name, num);
	default:
		break;
	}
}