// static : 계산, 처리
// instance: 데이터용
#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

class Circle {
public:
	static double circleArea(int r) {
		return r * r * 3.14;
	}
	static double cylinder(int r, int h) {
		return r * r * 3.14*h;
	}
};

class Student {
private:
	int age;
	string name;
public:
	void setName(string name) {
		this->name = name;
	}
	string getName(string name) {
		return name;
	}
};

int main() {
	//Circle c;
	//cout << c.circleArea(5) << endl;
	cout << Circle::circleArea(5) << endl;
	Student std[2];
	std[0].setName("aaa");
	std[1].setName("bb");
	Student* pstd = new Student[2];

	delete[] pstd;
	return 0;
}


