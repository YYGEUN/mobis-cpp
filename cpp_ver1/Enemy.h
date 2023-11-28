#pragma once
#include <iostream>

using namespace std;

class Enemy
{
private:
	float _HP;
	float _Defence;

public:
	Enemy(float d);
	float getNum() {
		return _HP;
	}
	float Caldmg(float num) {
		float realdmg = num * (1 - (_Defence / 100));
		return realdmg;
	}
	void setNum(float num) {
		_HP -= num;
	}
};

