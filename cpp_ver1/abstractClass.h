#pragma once
#include <iostream>

using namespace std;

class Sweet {
private:
protected:
	string _name;
	int _current;
	int _max;
public:
	Sweet();
	virtual ~Sweet();
	// Ŭ���� ���ο� �����Լ��� ������ virtual �Ҹ��ڸ� �����ؾ���
	// ���� �Ҹ��ڰ����ٸ� base�� ���Ǵ� Ŭ������ �ƴҰ�
	// �ݸ� ����� �������� Ŭ������ ����Ҹ��ڸ� �θ� vptr �Լ��� �����Ƿ� ��ü�� ũ�Ⱑ Ŀ�����ִ� ����������

	virtual void set(string name, int cur, int max);
	void output();

	virtual void func() abstract; // virtual void func() = 0; �����ǹ�

};


class Candy
	:public Sweet
{
public:
	// �θ��� �߻�Ŭ������ �ݵ�� �������̵� ����� ��밡����
	virtual void func() override
	{
		cout << "����!" << endl;
	}
};

class Gacha
	:public Sweet
{
public:
	// �θ��� �߻�Ŭ������ �ݵ�� �������̵� ����� ��밡����
	virtual void func() override
	{
		cout << "�̱�!" << endl;
	}
};