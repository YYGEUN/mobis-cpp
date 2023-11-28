#include "Board.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

Board::Board(int size)
	:size(size)
{
	int cnt = 1;
	int cnt2 = 1;
	//arr3.resize(size, vector<string>(size));

	for (int i = 0; i < size; i++)
	{
		Board::arr2[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			Board::arr2[i][j] = cnt2;
			cnt2++;
		}
	}
	
	//for (int i = 0; i < size; i++) {

	//	for (int j = 0; j < size; j++)
	//	{
	//		arr3[i][j] = to_string(cnt);
	//		cnt++;
	//	}
	//}
}
