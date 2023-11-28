#pragma once
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Board
{
private:
	int size;
	vector<vector<string>> arr3;
	int** arr2 = new int*[size];

public:
	Board(int size);

	void printboard() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
			{
				cout << arr3[i][j] << "      ";
			}
			cout << endl;
		}
	}

	void printboard2() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
			{
				if (arr2[i][j] == -1) {
					cout << "#" << "      ";
				}
				else {
					cout << arr2[i][j] << "      ";
				}
			}
			cout << endl;
		}
	}

	void checkboard(int num) {
		cout << "ok" << endl;
		if (num > size * size) {
			cout << "\n" << "번호가 존재하지않습니다." << "\n" << endl;
			return;
		}

		if (arr3[(num - 1) / size][(num - 1) % size] == "#") {
			cout << "\n" << "이미 체크되었습니다." << "\n" << endl;
			return;
		} 

		arr3[(num - 1) / size][(num - 1) % size] = "#";
	}

	void checkboard2(int num) {
		if (num > size * size) {
			cout << "\n" << "번호가 존재하지않습니다." << "\n" << endl;
			return;
		}

		if (arr2[(num - 1) / size][(num - 1) % size] == -1) {
			cout << "\n" << "이미 체크되었습니다." << "\n" << endl;
			return;
		}

		arr2[(num - 1) / size][(num - 1) % size] = -1;
	}

	int checkbingo() {
		int flag = 0;
		int cnt = 0;
		for (int i = 0; i < size; i++)
		{
			flag = 0;
			for (int j = 0; j < size-1; j++)
			{
				if (arr2[i][j] != arr2[i][j + 1]) {
					break;
				}
				else {
					cnt++;
				}
			}
			if (size - 1 == cnt) {
				flag = 1;
				return 1;
			}
		}
	}
};

