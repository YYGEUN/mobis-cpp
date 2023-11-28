#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

class Employee
{
private:
	char name[100];
	char addr[100];
public:
	Employee() {}
	Employee(char* name, char* addr) {
		strcpy(this->name, name);
		strcpy(this->addr, addr);
	}
	void ShowYourName() const { cout << "name: " << name << endl; }
	void ShowYourAddr() const { cout << "Addr: " << addr << endl; }

	virtual int GetPay() = 0;
	virtual void ShowSalaryInfo() = 0;
};

class Permanant :public Employee {
private:
	int per;
public:
	Permanant(char name[100], char addr[100], int per) : Employee(name, addr) { this->per = per; }
	int GetPay ()
	{
		return per;
	}
	void ShowSalaryInfo() {
		cout << per << endl;
	}
};

class Temporary :public Employee {
private:
	int per;
public:
	Temporary(char name[100], char addr[100], int temp,int date) : Employee(name, addr) { this->per = temp*date*8;}
	int GetPay()
	{
		return per;
	}
	void ShowSalaryInfo() {
		cout << per<< endl;
	}
};

class Manger :public Employee {
private:
	int per;
	char team[100];
public:
	Manger(char name[100], char addr[100], int per, char team[100]) : Employee(name, addr) { this->per = per; strcpy(this->team,team); }
	int GetPay()
	{
		return per;
	}
	void ShowSalaryInfo() {
		cout << "team= " << team << endl;
		cout << per << endl;
	}
};

int main()
{
	char n[100] = "기석";
	char a[100] = "선릉역";
	Employee* emp = new Permanant(n,a,20000000);

	emp->ShowYourName();
	emp->ShowYourAddr();
	Permanant* p = (Permanant*)emp;
	p->ShowSalaryInfo();

	char n1[100] = "한성";
	char a1[100] = "수원시청";
	Employee* emt = new Temporary(n1, a1, 10500,200);

	emt->ShowYourName();
	emt->ShowYourAddr();
	Temporary* T = (Temporary*)emt;
	T->ShowSalaryInfo();


	char n2[100] = "현식";
	char a2[100] = "역삼";
	char t1[100] = "클러스터";
	Employee* emm = new Manger(n2, a2, 13000000, t1);

	emm->ShowYourName();
	emm->ShowYourAddr();
	Manger* M = (Manger*)emm;
	M->ShowSalaryInfo();
}