
#include <iostream>

using namespace std;

class Father {
	int priVal;
protected:
	int proVal;
public:
	int pubVal;
	Father() { cout << "Father const call" << endl; 
	priVal = 0;
	proVal = 0;
	pubVal = 0;
	}
	~Father() {cout << "Father dest call" << endl;}
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
	~child() {
		cout << "child dest call" << endl;
	}
	void pubfn() { cout << "상속됨" << endl; }
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
	~baby() {
		cout << "baby dest call" << endl;
	}

	void babyfn() {
		proVal = 77;
		cout << proVal << endl;
	}

};

int main() {
	child ch;
	ch.pubVal = 20;
	ch.chVal = 22;
	ch.profn();

	baby by;
	by.babyfn();
	ch.profn();
	return 0;
}