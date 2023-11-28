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
		if (sz < a) {
			int* tmp = new int[a];
			memcpy(tmp, ptr, sizeof(int)*sz);
			delete[] ptr;
			sz = a;
			ptr = tmp;
		}
		else {

		}
	}

	int size() { return sz; }

	//void operator[](int a) {
	//	ptr[a] = b;
	//}
};

int main()
{
	Vector v(4, 2); // 4개를 0으로 초기화
	cout << v.size() << endl;

	v.resize(8);
	cout << v.size() << endl;

	//v[0] = 5;
	//cout << v[0] << endl;

	return 0;


}