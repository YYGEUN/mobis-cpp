#include <iostream>
#include "avante.h"
#include "genesis.h"

int main() {
	BaseCar* car;
	BaseCar* car2 = new BaseCar;
	avante* avang = new avante;
	genesis* gene = new genesis;

	// ��ĳ����
	car = static_cast<BaseCar*>(avang);
	car->setname("avang");
	car->output();

	// ��ĳ����
	static_cast<BaseCar*>(gene)->setname("gene");
	delete(gene);

	car2->output();
	delete(car2);

	//�ٿ�ĳ����

	avang->output();
	dynamic_cast<avante*>(avang)->setname("22");
	avang->output();

	delete(avang);
	return 1;
}