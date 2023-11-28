#pragma once
#include <iostream>
#include "Enemy.h"
#include "soccer.h"

using namespace std;

int main() {
	float damage;
	int Hp;

	soccer s1(1.2f);
	Enemy e1(10.0f);

	damage = s1.getNum_Hit(20.0f);

	Hp = e1.getNum();
	cout << "피격전 : " << Hp << endl;
	e1.setNum(e1.Caldmg(damage));

	Hp = e1.getNum();
	cout << "피격후 : " << Hp << endl;
}