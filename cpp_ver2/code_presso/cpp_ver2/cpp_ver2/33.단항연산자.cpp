#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

class OpTest {
private:
	int a = 0,b = 0;
public:
	void operator++() {
		cout << "pre ++ call" << endl;
		a = a + 1;
		b = b + 1;
	}
	OpTest& operator++(int) {
		cout << "after ++ call" << endl;
		a = a + 1;
		b = b + 1;
		return *this;
	}
	void show() {
		cout << "a = " << a << "  b = " << b << endl;
	}
};

class MyArr {
	int* buff;
	int size;
public:
	MyArr(int s) {
		buff = new int[s];
		size = s;
	}
	int& operator[](int idx) {
		return buff[idx];
	}
	~MyArr() {
		delete[] buff;
	}
};

int main() {
	//OpTest obj;
	//++obj; // obj.operator++()
	//obj++; //obj.operator++(int)
	//(obj++)++; 
	//obj.show();

	MyArr arr(3);
	arr[0] = 100; // arr.operator(0) = 100; Lv 값이 래퍼런스로 가져와서 입력도가능
	int rst;
	rst = arr[0]; // rst = arr.operator(0);  값을 읽어옴
	cout << "rst = " << rst << endl;

	return 0;
}