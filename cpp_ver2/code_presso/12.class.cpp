#include <stdio.h>
#include <iostream>
#include <typeinfo>
using namespace std;

// 1. ��� ����Լ��� 1��° ���ڿ� Ŭ�����̸�* this �߰�
// 2. ��������� : this->���������
// 2. ��ü.����Լ� ==> ��ü.����Լ�( ��ü�ּ� ,...)
// 3. �������Լ� ���ǰ� ������ ����Ʈ������ �߰�
class Test{
private:
	int a;
	int b;
public:
	//void setData(Test* this, int x, int y)
	void setData(int x, int y) 
	{
		a = x; //this->a = x
		b = y; //this->b = y
	}
	//void show(Test* this)
	void show() {
		cout << "a=" << a << " b=" << b << endl;
		//cout << "a=" << this->a << " b=" << this->b << endl;
	}
	//Test(){}
};
int main(){
	Test tt;
	tt.setData(100, 200); //tt.setData(&tt, 100, 200);
	tt.show(); // tt.show(&tt);

	return 0;
}