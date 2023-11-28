#pragma once
#include <iostream>

using namespace std;

// static�� ������������ ����������
// static�� �������� �����Լ����� ������ ��ó�� ����
static int __number = 0;


class Class1
{
private:
	int num;
	int result = 0;

public:
	//Class1();
	//~Class1();

	//��ü�� ����Լ��� ȣ���ҋ� �����Ϸ��� ������Լ� �տ� �ش簴ü�̸��� ����ؼ� ��ȯ�� ȣ��
	// ��ü ���ο� �������, �Լ��տ��� this->�� ���������� ����

	void InPutNum(int num) {
		this->num = num; 
		// this�� ���� Ŭ������ ��Ī�ϴ� ������
		// �Ű�������� Ŭ������ ��������� ��ĥ�������� �ѹ��� ��������� ǥ�����ִ°�
	}

	void Print() { cout << __number << endl; }

	//Class1& Plus(int value) { result += value; return *this;}
	//Class1& Minus(int value) { result -= value; return *this; }
	//Class1& Times(int value) { result *= value; return *this; }

	Class1* Plus(int value) { __number += value; return this; }
	Class1* Minus(int value) { __number -= value; return this; }
	Class1* Times(int value) { __number *= value; return this; }

};

