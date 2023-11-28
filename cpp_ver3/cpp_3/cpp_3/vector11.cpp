//vecto11.cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{

	//지역변수는 {}을 벗어날떄까지 메모리를 할당받고 있어 제거가 불가능하다

	int n = 0;
	//int size = 4;
	//int* score = new int[size];

	vector<int> v;

	while (1) {
		cin >> n;
		if (n == -1)
			break;
		v.push_back(n);
		//score[count++] = n;
		//if (count == size) {
		//	size *= 2;
		//	int* containtmp = new int[size];
		//	memcpy(containtmp, score, sizeof(int) * size / 2);
		//	delete[] score;
		//	score = containtmp;
		//}
		// 이블록을 넘어오면서 containtmp 파괴됨
	}

	cout << "입력된 숫자갯수 : " << v.size() << endl;
	cout << "할당된 버퍼크기 : " << v.capacity() << endl;

	//for (int i = 0; i < v.size(); i++) {
	//	cout << v[i] << endl;
	//}

	for (int i : v) {
		cout << i << endl;
	}

	//delete[] score;

	return 0;
}


// list : 모든요소를 따로 보관 --> 중간에 넣기 빠름
// vector : 모든요소를 연속된 메모리에 보관 --> 앞뒤에 추가하는거 빠름 , 전체순회 빠름