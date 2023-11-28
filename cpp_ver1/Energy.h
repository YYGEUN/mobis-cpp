#pragma once
#include "ICAR.h"

class UseEnergy
	: public ICAR
{
public:
	virtual void Info(string type,int num) override;
	virtual void Active() override;
	virtual void InjectFuel(int num) override;
	virtual void ReadFuel() override;
};

void menu(ICAR* icar);