#include <iostream>
#include <cstring>

template<typename T>	// 클래스가 아닌 "클래스의 틀(template)" 을 만들겠다고 알려주는것
class vector
{
	T* ptr;
	int  sz;
public:
	vector(int size, T value) : sz(size)
	{
		ptr = new T[sz];

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
			T* tmp = new T[newsize];
			memcpy(tmp, ptr, sizeof(T)*size);

			delete[] ptr;
			ptr = tmp;
			size = newsize;
		}
		else 
		{
		
		}
	}
	T& operator[](int idx)  { 	return ptr[idx]; } 

	int size() { return sz;}
	bool empty() { return sz == 0;}
};

int main()
{
	vector<int> v(4, 0);

	v[1] = 10; 

	std::cout << v[1] << std::endl;
	
}







