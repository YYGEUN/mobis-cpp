#pragma once
#include<iostream>
#include "Board.h"
using namespace std;

void main() {
	int size;
	int num;
	cout << "�� �ٵ��� ������ �Է� : ";
	cin >> size;

	Board br(size);

	while (1) {
		br.printboard2();
		cout << "�� ��ȣ �Է� : ";
		cin >> num;
		br.checkboard2(num);
	}

	return;
}