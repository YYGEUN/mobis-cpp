#include <iostream>
#include <string>

using namespace std;

class Test {
private:
	//int a=0;
	//int b=0;
	//const double R=3.14;
	int a;
	int b;
	const double R;
public:
	Test(): R(3.14), a(0), b(0){
		cout << "constructor call" << endl;
	}
	Test(int x, int y):R(3.14) {
		//R = 3.14;
		a = x;
		b = y;
		cout << "arg constructor call" << endl;
	}
	~Test() {
		cout << "dest call" << endl;
	}
	//void setR(int r) {
	//	R = r;
	//}
	//const ����Լ�; ��������� ����Ұ�
	int getA() const
	{
		//a = 100;
		return a;
	}
	void setData(int x, int y) {
		a = x;
		b = y;
	}
	void show() {
		cout << "a=" << a << " b=" << b << endl;
	}
	void show() const{
		cout << "const show call" << endl;
		cout << "a=" << a << " b=" << b << endl;
	}
};
// const Test& aa =tt;
//void fn( Test aa)
void fn(const Test& aa) 
{
	aa.show();
}
int main(){
	//Test tt;
	//const Test tt; // const ��������͸� ȣ�Ⱑ��
	//tt.setData(10, 20);
	//tt.show();
	//Test tt;
	//const Test& r = tt;
	//printf("r�ּ�:%d\n", &r);
	//printf("tt�ּ�:%d\n", &tt);
	////r.setData(100, 200);//r.setData(&r, 100, 200);
	//r.show();
	//tt.show();//tt.show(&tt);

	Test tt;
	fn(tt);

	return 0;
}