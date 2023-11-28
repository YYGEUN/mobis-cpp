#pragma once
#include "Energy.h"


// 강한결합 상태 인자를 세분화해서 그에 따른 함수가 각각 필요
class Engine
{
private:
	UseEnergy* USE;
public:
	void useFuel(UseEnergy* USE) {
		USE->Active();
	}
};

//약한결합 상태 인터페이스를 받아 그에 따라 작동하도록 할수있음 
// --> 확장성이 높음 추후 배터리의 종류가 추가되어도 여기 함수 추가할필요없음
class Engine2
{
private:

public:
	void setinfo(ICAR* icar,string name,int num) {
		icar->Info(name, num);
	}
	void view(ICAR* icar) {
		icar->ReadFuel();
	}
	void charge(ICAR* icar, int num) {
		icar->InjectFuel(num);
	}
	void act(ICAR* icar) {
		icar->Active();
	}
};