#pragma once
#include "motherclass.h"

class childclass : public motherclass
{
public:
	childclass() {
		cout << "�ڽ� Ŭ���� ����" << endl;
		_livingMoney = 7000; // protected ���� ���� ����
		//_Megg = 1000; // private ���� �Ұ�
	}

	~childclass() {
		cout << "�ڽ� Ŭ���� �Ҹ�" << endl;
	}
};

class lastclass : public childclass
{
public:
	lastclass() {
		cout << "��Ʈ Ŭ���� ����" << endl;
		_livingMoney = 9000; // protected ���� ���� ����
		//_Megg = 1000; // private ���� �Ұ�
	}

	~lastclass() {
		cout << "��Ʈ Ŭ���� �Ҹ�" << endl;
	}
};