#include "engine.h"

int main()
{
	Engine* engine = new Engine;
	Engine2* engine2 = new Engine2;

	ICAR* gasoline = new UseEnergy;
	ICAR* electrobattery = new UseEnergy;
	ICAR* IONIC = new UseEnergy;

	engine2->setinfo(gasoline,"gasoline", 33);
	engine2->setinfo(electrobattery, "electro", 0);
	
	engine2->view(gasoline);
	engine2->act(gasoline);
	engine2->act(electrobattery);

	menu(IONIC);
	engine2->act(IONIC);
	return 0;
}