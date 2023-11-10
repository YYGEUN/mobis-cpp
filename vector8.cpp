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
	int& operator[](int idx)  { 	return ptr[idx]; } 

	// 이제 vector를 사용하는 사용자를 고려해서..
	// 사용자들이 좋아할 만한 좋은 멤버 함수를 제공해 주세요
	int size() { return sz;}
	bool empty() { return sz == 0;}
};

int main()
{
	vector v(4, 0);

	v[1] = 10; // v.operator[](1) = 10

	std::cout << v[1] << std::endl;
	
}







