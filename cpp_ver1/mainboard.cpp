#pragma once
#include<iostream>
#include "Board.h"
using namespace std;

void main() {
	int size;
	int num;
	cout << "▶ 바둑판 사이즈 입력 : ";
	cin >> size;

	Board br(size);

	while (1) {
		br.printboard2();
		cout << "▶ 번호 입력 : ";
		cin >> num;
		br.checkboard2(num);
	}

	return;
}