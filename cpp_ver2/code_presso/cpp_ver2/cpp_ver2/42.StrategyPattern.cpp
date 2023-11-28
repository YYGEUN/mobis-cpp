#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------------------
// 정렬 인터페이스
class 정렬_인터페이스
{
public:
	virtual void 정렬() = 0;
};
//------------------------------------------------------------------
// 퀵 정렬 알고리즘 클래스
class 퀵정렬 : public 정렬_인터페이스
{
public:
	void 정렬() override { cout << "퀵 정렬" << endl; }
};
//------------------------------------------------------------------
// 버블 정렬 알고리즘 클래스
class 버블정렬 : public 정렬_인터페이스
{
public:
	void 정렬() override { cout << "버블 정렬" << endl; }
};
//------------------------------------------------------------------
// 머지 정렬 알고리즘 클래스
class 머지정렬 : public 정렬_인터페이스
{
public:
	void 정렬() override { cout << "머지 정렬" << endl; }
};

//------------------------------------------------------------------
// 정렬 관리자 클래스
class 정렬관리자
{
public:
	정렬관리자() : pInterface(0) {}
	~정렬관리자() { if (pInterface) delete pInterface; }
public:
	void 정렬() { pInterface->정렬(); }
	void 인터페이스_설정(정렬_인터페이스* _interface)
	{
		if (pInterface) delete pInterface;
		pInterface = _interface;
	}
private:
	정렬_인터페이스* pInterface;
};
//------------------------------------------------------------------
// Main
int main()
{
	정렬관리자* pManager = new 정렬관리자();
	pManager->인터페이스_설정(new 버블정렬());
	pManager->정렬();
	pManager->인터페이스_설정(new 퀵정렬());
	pManager->정렬();
	pManager->인터페이스_설정(new 머지정렬());
	pManager->정렬();
	delete pManager;
	return 0;
}
