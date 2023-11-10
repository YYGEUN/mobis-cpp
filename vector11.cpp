#include <iostream>
#include <cstring> 
#include <vector>

int main()
{
	int n = 0;
	std::vector<int> v; // 크기가 0인 동적 배열

	while(1)
	{
		std::cin >> n;

		if ( n == -1 ) 
			break;

		v.push_back(n);
	}

	std::cout << "입력된 요소의 갯수 : " << v.size()     << std::endl;
	std::cout << "할당된 버퍼의 크기 : " << v.capacity() << std::endl;

	for(auto e : v)
	{
		std::cout << e << ", ";
	}
}
// C 언어는 vector 가 없어서, "직접 만들어서 사용" 해야 하지만
// C++ 언어에는 vector, list, stack, queue 등의 좋은 도구가 아주 많이 있다
// => STL!!!






