#include "abstractClass.h"

void main()
{
	Sweet* candy = new Candy;
	candy->set("�ڵ�", 20, 100);
	candy->output();

	delete(candy);

	Gacha* Pgacha = new Gacha;
	Pgacha->set("����", 10, 11);
	Pgacha->output();
	//Gacha gacha;

}