#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

class Test {
private:
	int a;
	int b;
};

void fn()
{
	Test* p = new Test;
	//delete p;

}
int main()
{
	// f5 ����� ����� �޸� ���� Ȯ��
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	fn();
	fn();
	return 0;
}