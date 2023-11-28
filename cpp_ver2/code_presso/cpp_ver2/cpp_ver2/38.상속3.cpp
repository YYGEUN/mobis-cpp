#include <iostream>

using namespace std;

//class Father {
//	int priVal;
//protected:
//	int proVal;
//public:
//	int pubVal;
//	Father() {
//		cout << "Father const call" << endl;
//		priVal = 0;
//		proVal = 0;
//		pubVal = 0;
//	}
//	Father(int a,int b, int c) {
//		cout << "Father const call" << endl;
//		priVal = a;
//		proVal = b;
//		pubVal = c;
//	}
//	~Father() { cout << "Father dest call" << endl; }
//	void setpri() {
//		priVal = 33;
//	}
//};

class Father {
private:
	int priVal;
protected:
	int proVal;
public:
	int pubVal;
	Father() { cout << "father const call" << endl; priVal = 0; proVal = 0; pubVal = 0; }
	Father(int a, int b, int c) {
		cout << "arg father const call" << endl;
		priVal = a; proVal = b; pubVal = c;
	}
	~Father() { cout << "father dest call" << endl; }
	void pubFn() { cout << "pubfn" << endl; }
};

class child
	:public Father
{
public:
	int chVal;
	child() {
		cout << "child const call" << endl;
		chVal = 0;
	}
	child(int n):Father(n,n*2,n*3) {
		cout << "child arg call" << endl;
		chVal = n;
	}
	~child() {
		cout << "child dest call" << endl;
	}
	void profn() {
		cout << proVal << endl;
	}
};

class baby
	:public child // protected child 로 받으면 public도 protected로 받아진다--> 직접호출 불가, 내부적으로 이용가능
	// private childe 로 상속 받으면 전부 private로 되고 추가로 다른 함수에서 상속 받기어렵다
// public : private 제외 멤버를 접근권한 그대로 상속
// protected : protected 접근권한자로 상속 (public--> protected 화)
//private : private 접근권한자로 상속 
{
public:
	int babyVal;
	baby() {
		cout << "baby const call" << endl;
		babyVal = 0;
	}
	baby(int n)
		:child(n*2){ // 베이비에서 차일드 초기화
		cout << "baby arg call" << endl;
		babyVal = n;
	}
	~baby() {
		cout << "baby dest call" << endl;
	}

	void pro_babyfn() {
		proVal = 77;
	}
};

int main() {
	baby by(100);
	cout << by.pubVal << endl;
	return 0;
}