#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

//c언어에서 프로그램은 
// 1. main 함수의 1번째 줄부터 순차적으로 실행되는 실행흐름이다.
// 2. 실행흐름을 변경하려면 제어문 사용
// 3. 실행흐름을 반복하려면 반복문 사용
// 4. 중복되는 코드는 묶어서 함수 사용
// 5. 프로그램 기본단위는 함수

// 장점 : 실제 CPU가 동작하는 방식과 동일 --> 빠름
//		  메모리 사용량도 적음

// 단점 : 유연성이부족, 변화 대응 어려움
// 
// 
//	아래코드에서 메뉴가 추가되면 여러곳이 수정됨
//	하위메뉴가 존재하면 복잡해짐

using namespace std;

int main()
{
	printf("1. 기기등록\n");
	printf("2. 기기삭제\n");
	printf("메뉴를 선택하세요 >>\n");

	int cmd;
	cin >> cmd;
	
	switch (cmd)
	{
	case 1: 
		break;
	case2:
		break;
	default:
		break;
	}
}