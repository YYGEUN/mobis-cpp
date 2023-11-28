#include <iostream>
#include<cstring>

using namespace std;

class Vector
{
private:
	int sz;
	int* ptr;
public:
	Vector(int a, int b)
		:sz(a)
	{
		ptr = new int[sz];
		for (int i = 0; i < sz; i++) {
			ptr[i] = b;
		}
	}
	~Vector()
	{
		delete[] ptr;
	}

	void resize(int a) {
		int min;
		if (sz < a) {
			min = sz;
		}
		else {
			min = a;
		}
		int* tmp = new int[min];
		memcpy(tmp, ptr, sizeof(int) * min);
		delete[] ptr;
		sz = a;
		ptr = tmp;
	}

	bool empty() { return sz == 0; }

	int size() { return sz; }

	int& operator[](int a) {
		//레퍼런스 값으로 리턴
		return ptr[a];
	}

};

int main()
{
	Vector v(4, 2); // 4개를 0으로 초기화
	//cout << v.size() << endl;

	v.resize(2);
	//cout << v.size() << endl;

	v[0] = 5;
	//cout << v[0] << endl;
	for (int i = 4; i < 8; i++) {
		v[i] = 7;
	}

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	return 0;


}