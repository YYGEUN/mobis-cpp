#include "abstractClass.h"

void main()
{
	Sweet* candy = new Candy;
	candy->set("자두", 20, 100);
	candy->output();

	delete(candy);

	Gacha* Pgacha = new Gacha;
	Pgacha->set("레어", 10, 11);
	Pgacha->output();
	//Gacha gacha;

}