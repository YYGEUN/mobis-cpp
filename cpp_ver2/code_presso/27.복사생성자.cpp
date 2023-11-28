#include <iostream>
#include <string>
using namespace std;

class Student {
private:
	int num;
	char* name;
public:
	Student(int num, const char* name) {
		cout << "const call" << endl;
		int n;
		this->num = num;
		n = strlen(name) + 1;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, n, name );
	}
	void show() {
		//cout << this->num << " " << this->name << endl;
		printf("num=%d\n", this->num);
		printf("name=%s\n", this->name);
	}
	~Student() {
		cout << "dest call" << endl;
		delete[] name;
	}
	Student(const Student& r) 
	{
		cout << "copy const call" << endl;
		this->num = r.num;
		//this->name = r.name;
		int n;
		n = strlen(r.name) + 1;
		this->name = new char[n];
		strcpy_s(this->name, n, r.name);
	}
	Student() {
		this->num = 0;
		this->name = 0;
	}
	Student& operator=(const Student& r)
	{
		cout << "= op call " << endl;
		this->num = r.num;
		//this->name = r.name;
		int n;
		n = strlen(r.name) + 1;
		this->name = new char[n];
		strcpy_s(this->name, n, r.name);
		return *this;
	}
};
int main(){
	Student s1(10, "kim");
	//Student s2(20, "park");

	//shallow copy
	//Student s2 = s1;//Student s2(s1) Student s2 = Student(s1)
	Student s2;
	s2 = s1;
	s1.show();
	s2.show();

	return 0;
}