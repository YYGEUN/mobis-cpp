#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
	char name[100];
	char addr[100];
public:
	Employee() {}
	Employee(const char* name, const char* addr) {
		strcpy_s(this->name, 100, name);
		strcpy_s(this->addr, 101, addr);
	}
	virtual ~Employee() {}
	void ShowYourName() const { cout << "name: " << name << endl; }
	void ShowYourAddr() const { cout << "Addr: " << addr << endl; }

	void showall() {
		ShowYourName();
		ShowYourAddr();
		ShowSalaryInfo();
	}

	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class Permanant :public Employee {
private:
	int money;
public:
	Permanant(int m, const char* name, const char* addr) :Employee(name, addr), money(m) {};
	~Permanant() {};
	virtual int GetPay() const {
		return money / 12;
	}
	virtual void ShowSalaryInfo()const {
		cout << GetPay() << endl;
	}
};

class Temporary : public Employee {
private:
	int money;
	int day;
public:
	Temporary(int m, int d, const char* name, const char* addr) :Employee(name, addr), money(m), day(d) {};
	~Temporary() {};
	virtual int GetPay() const {
		return money * day * 8;
	}
	virtual void ShowSalaryInfo() const {
		cout << GetPay() << endl;
	}
};

class Maneger :public Employee {
private:
	int money;
	string team;
public:
	Maneger(int m, string s, const char* name, const char* addr) :Employee(name, addr), money(m), team(s) {};
	~Maneger() {};
	virtual int GetPay() const {
		return money / 12;
	}
	virtual void ShowSalaryInfo() const {
		cout << GetPay() << endl;
	}
};

void show(Employee* employee) {
	employee->ShowSalaryInfo();
	delete employee;
}

class EmpProc {
public:
	static void empInfo(Employee* employee) {
		employee->ShowYourName();
		employee->ShowYourAddr();;
		employee->ShowSalaryInfo();
		delete employee;
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//EmpProc::empInfo(new Permanant(3000, "梯熱團", "憮選衛"));
	//EmpProc::empInfo(new Temporary(9, 20, "梯熱團", "熱雖掘羶"));
	//EmpProc::empInfo(new Maneger(3000, "憲夥", "梯熱團", "熱雖掘羶"));

	Employee* emp = new Permanant(3000, "a", "abc");
	emp->showall();

	Employee* emp1 = new Maneger(6000,"dsad", "aa", "def");
	emp1->showall();

	//Employee* employee1 = new Permanant(3000, "梯熱團","憮選衛");
	//Employee* employee2 = new Temporary(9, 20, "梯熱團", "熱雖掘羶");
	//Employee* employee3 = new Maneger(3000, "憲夥", "梯熱團", "熱雖掘羶");
	/*
	employee1->ShowSalaryInfo();
	employee2->ShowSalaryInfo();
	employee3->ShowSalaryInfo();
	*/
	//show(new Permanant(3000, "梯熱團", "憮選衛"));
	//show(new Temporary(9, 20, "梯熱團", "熱雖掘羶"));
	//show(new Maneger(3000, "憲夥", "梯熱團", "熱雖掘羶"));

}