#pragma once
#include <iostream>

using namespace std;

class soccer
{
private:
	float _Dmg_mult;

public:
	soccer(float d);

	float getNum_Hit(float d) {
		return _Dmg_mult * d;
	}
};

