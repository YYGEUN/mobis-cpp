#include <iostream>
#include <string>
#include <tuple>
using namespace std;

// ���ϰ��� ������
tuple<int, double, string> getTuple() {
	int a = 10;
	double b = 3.14;
	string s = "hello";
	return make_tuple(a, b, s);
}

int main()
{
	int a;
	double b;
	string c;
	tie(a, b, c)=   getTuple(); // c++ 11����
	auto [x, y, z] = getTuple(); // c++ 15����
	cout << "x=" << x << "y=" << y << "z=" << z << endl;

	return 0;
}