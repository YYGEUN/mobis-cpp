#include <iostream>
#include "avante.h"
#include "genesis.h"

int main() {
	BaseCar* car;
	BaseCar* car2 = new BaseCar;
	avante* avang = new avante;
	genesis* gene = new genesis;

	// 업캐스팅
	car = static_cast<BaseCar*>(avang);
	car->setname("avang");
	car->output();

	// 업캐스팅
	static_cast<BaseCar*>(gene)->setname("gene");
	delete(gene);

	car2->output();
	delete(car2);

	//다운캐스팅

	avang->output();
	dynamic_cast<avante*>(avang)->setname("22");
	avang->output();

	delete(avang);
	return 1;
}