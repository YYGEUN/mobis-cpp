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

//------------------------------------------------------------------
// 정렬 관리자 클래스
class EmpContext
{
public:
	EmpContext() : pInterface(0) {}
	~EmpContext() { if (pInterface) delete pInterface; }
public:
	void Empinfo() {
		pInterface->ShowYourName();
		pInterface->ShowYourAddr();
		pInterface->ShowSalaryInfo();
	}
	void change_Strategy(Employee* _interface)
	{
		if (pInterface) delete pInterface;
		pInterface = _interface;
	}
private:
	Employee* pInterface;
};
//------------------------------------------------------------------


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	EmpContext* emp = new EmpContext();
	emp->change_Strategy(new Permanant(5000,"응","집"));
	emp->Empinfo();
	emp->change_Strategy(new Temporary(5, 30,"네", "밖"));
	emp->Empinfo();
	emp->change_Strategy(new Maneger(10000,"옆집", "ㅇㅇ", "집"));
	emp->Empinfo();
	delete emp;

}