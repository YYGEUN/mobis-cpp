#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

//struct Calendar {
//	int month;
//};
// ĸ��ȭ
// ��������� ���� X
// ����Լ��� ���� r/w
class Calendar{
private:
	int month;
public:
	int setMonth(int month) {
		if (month < 1 || month > 12)
			printf("wrong month\n");
		else
			this->month = month;
	}
	int getMonth() {
		return month; //this->month;
	}
};

int main() {
	Calendar cal;
	//cal.month = 13; // �������� ���Ἲ
	cal.setMonth(11); // cal.setMonth( &cal, 11 )
	cout << cal.getMonth() << endl;
	// cal.getMonth( &cal )
	return 0;
}