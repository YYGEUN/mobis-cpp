#include <stdio.h>

#define myendl "\n"

class myOstream {
public:
	myOstream& operator<<(const char* str) {
		printf("%s", str);
		return *this;
	}
	myOstream& operator<<(const int n) {
		printf("%d", n);
		return *this;
	}
	myOstream& operator<<(const float f) {
		printf("%f", f);
		return *this;
	}
};

myOstream myout;

int main()
{
	int num = 100;
	myout << "num = " << num << myendl;
	myout << "hello" << myendl;
	myout << "korea  " << "hello";
	return 0;
}