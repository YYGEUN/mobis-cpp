#include <iostream>
#include "childclass.h"
#include "horse.h"

int main() {

	////// 정적 할당
	//childclass cc;
	//cc.output();

	//// 동적 할당
	//motherclass* cc2 = new lastclass; // 최고위 클래스를 포인터로 지정하면 내부의 상속된 클래스들을 편하게 불러올수있다.
	//cc2->_freemoney = 50000;
	//cc2->output();
	//delete(cc2);

	//lastclass lc;
	//lc.output();

	// 오버라이드-------------
	
	horse hr;
	hr.Boarding();  // 부모클래스의 함수명과 같으면 자식클래스에서 덮어 씌움
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