#include <iostream>
#include <cstring>

// 동적 배열을 재사용 가능하게 타입으로 설계해 봅시다
// 동적 배열을 흔히 "vector" 라고 부릅니다.

// step 1. 생성자, 소멸자 만들기
class vector
{
	int* ptr;
	int  sz;
public:
	vector(int size, int value) : sz(size)
	{
		ptr = new int[sz];

		for( int i = 0; i < sz; i++)
		{
			ptr[i] = value;
		}
	}
	~vector() { delete[] ptr; }
};
int main()
{
	vector v(4, 0); // 4개를 0으로 초기화

//	std::cout << v.size() << std::endl;
//	v[0] = 5;
//	std::cout << v[0] << std::endl;
}





