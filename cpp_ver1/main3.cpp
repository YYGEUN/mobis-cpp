#include <iostream>
#include "childclass.h"
#include "horse.h"

int main() {

	////// ���� �Ҵ�
	//childclass cc;
	//cc.output();

	//// ���� �Ҵ�
	//motherclass* cc2 = new lastclass; // �ְ��� Ŭ������ �����ͷ� �����ϸ� ������ ��ӵ� Ŭ�������� ���ϰ� �ҷ��ü��ִ�.
	//cc2->_freemoney = 50000;
	//cc2->output();
	//delete(cc2);

	//lastclass lc;
	//lc.output();

	// �������̵�-------------
	
	horse hr;
	hr.Boarding();  // �θ�Ŭ������ �Լ���� ������ �ڽ�Ŭ�������� ���� ����
	//Vehicle vi;
	//vi.Boarding();
	//horse3 hr3;
	//hr3.Boarding();
	//hr3.Landing();
	//hr3.run();
	
	Move mv;
	mv.Boarding();
	mv.summon();
	mv.die();


	//horse2 hr2;
	//hr2.Boarding();



	return 1;
}