#include <iostream>

// iterator 원리 - 몰라도 되지만, 알고 싶은 분은 참고 하세요

// 1. 내부적으로 실제 포인터를 가지고 있다가
// 2. ++, * 연산자를 재정의해서 포인터 처럼 보이게 하는것
// 3. ++ 의 구현에서 어떻게 다음으로 이동할지를 결정하면 됩니다.

// 아래 코드는 int 타입의 배열(연속된)을 포인터 대신 사용가능한 반복자 입니다.
class array_iterator
{
	// 1. 내부적으로는 실제 포인터 보관
	int* ptr;
public:
	array_iterator(int* p) : ptr(p) {}

	// 핵심은 아래 2개의 멤버 함수 입니다.
	array_iterator& operator++()
	{
		// 2. 연속된 메모리이므로 실제 멤버로 있는 포인터도 ++
		++ptr;	
		// ptr = ptr->next;   // linked list 를 위한 반복자 였다면 이렇게 구현

		return *this;   // "operator++()" 연산자는 자신을 참조로 반환해야 합니다.
						// C++의 문법 규칙
	}
	int& operator*() { return *ptr;}
};
int main()
{
	int x[5] = {1,2,3,4,5};

	array_iterator ai = x;

	// ai 는 분명 포인터가 아닌 객체 입니다.
	// 하지만, 사용법은 포인터와 동일합니다.
	*ai = 10;

	std::cout << *ai << std::endl; // 10
	++ai;
	std::cout << *ai << std::endl; // 2
}