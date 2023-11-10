#include <iostream>
#include <cstring>


// step 2.

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
		if ( newsize > size) // 크기가 커지는 경우
		{
			int* tmp = new int[newsize];
			memcpy(tmp, ptr, sizeof(int)*size);

			delete[] ptr;
			ptr = tmp;
			size = newsize;
		}
		else 
		{
			// 크기가 작아지는 경우
		}
	}
};

int main()
{
	vector v(4, 0);

	v.resize(8);
}







