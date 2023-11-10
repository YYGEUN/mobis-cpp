#include <iostream>
#include <cstring>


// step 3.

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

	void resize( int newsize)
	{
		if ( newsize > size) 
		{
			int* tmp = new int[newsize];
			memcpy(tmp, ptr, sizeof(int)*size);

			delete[] ptr;
			ptr = tmp;
			size = newsize;
		}
		else 
		{
		
		}
	}
	// [] 연산자 재정의 : 객체를 배열 처럼 사용할수 있게 하고 싶을 때 주로 사용
//	int operator[](int idx)  { 	return ptr[idx]; } 
				// => 이렇게 만들면 ptr[idx] 에 있는 "값" 이 반환 됩니다.
				// => 그래서, "v[1] = 10" 이 에러 입니다.
	int& operator[](int idx)  { 	return ptr[idx]; } 
				// => 이렇게 반환하면 "ptr[idx]" 라는 "메모리의 별명" 이 반환
				// => "v[1] = 10" 이 가능해 집니다.
				// => 레퍼런스 반환 이라는 개념입니다.
};

int main()
{
	vector v(4, 0);

	// 결국 vector 는 "크기 변경이 가능한 배열" 입니다.
	// 배열과 동일하게 사용할수 있게 해야 합니다.

	v[1] = 10; // v.operator[](1) = 10

	std::cout << v[1] << std::endl;
	
}







