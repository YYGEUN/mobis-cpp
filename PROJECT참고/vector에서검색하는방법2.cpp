#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8};

	// 1. v에서 3이 있는 위치를 찾으려면 아래 처럼 합니다.
	auto p = std::find(v.begin(), v.end(), 3);

	// 2. 반환값 p는 3이 있는 곳을 가리키는 반복자(포인터) 입니다.
	//    만약 3이 없었다면 p 는 마지막 다음(v.end()) 가 반환 됩니다.
	if( p == v.end())
	{
		std::cout << "3이 없습니다." << std::endl;
	}
	else 
	{
		std::cout << "찾았습니다. : " << *p << std::endl;

		// 3을 제거하려면 아래 처럼하세요
		// v.erase 의 인자로 3의 위치를 가리키는 반복자 전달
		v.erase(p); 
	}

	// 3. 
}