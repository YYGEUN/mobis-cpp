#pragma once
#include "Energy.h"


// ���Ѱ��� ���� ���ڸ� ����ȭ�ؼ� �׿� ���� �Լ��� ���� �ʿ�
class Engine
{
private:
	UseEnergy* USE;
public:
	void useFuel(UseEnergy* USE) {
		USE->Active();
	}
};

//���Ѱ��� ���� �������̽��� �޾� �׿� ���� �۵��ϵ��� �Ҽ����� 
// --> Ȯ�强�� ���� ���� ���͸��� ������ �߰��Ǿ ���� �Լ� �߰����ʿ����
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