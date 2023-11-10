// vector2.cpp
#include <iostream>

int main()
{
	// 사용자가 -1 을 입력할때 까지 계속 입력 받고 싶다.
	int n = 0;
	
	int size = 4;
//	int score[4]; // 이렇게 만들때 더이상 필요없을때 즉시 파괴 할수 없습니다.
				  // 지역변수의 수명은 항상 규칙 이 정해져 있습니다.
				  // {} 을 벗어날때 파괴

	int* score = new int[size]; // 이렇게 하면 더이상 필요 없을때 즉시 파괴할수있습니다.
	int count = 0;

	while(1)
	{
		std::cin >> n;

		if ( n == -1 ) 
			break;

		score[count++] = n;

		if( count == size )
		{
			// 1. 버퍼(메모리)가 부족하므로 재할당 필요 
			int* tmp = new int[size*2];

			// 2. 기존 버퍼의 내용을 새로운 버퍼에 복사
			memcpy(tmp, score, sizeof(int)*size);
				// => score가 가리키는 곳의 메모리를
				// => tmp  가 가리키는 곳의 메모리에 복사


			// 3. 기존 버퍼는 필요 없으므로 제거
			delete[] score;  
				// => score를 지우는 것이 아니라!!!
				//    score가 가리키는 곳을 지우는 것!

			// 4. score 포인터 변수가 새로운 버퍼를 가리키도록
			score = tmp;	
				// => tmp 자체는 {} 벗어날때 자동으로 파괴

			// 5. size 변수 변경
			size = size * 2;
		}
	}

	std::cout << "입력된 요소의 갯수 : " << count << std::endl;
	std::cout << "할당된 버퍼의 크기 : " << size << std::endl;

	for( int i = 0; i < size; i++)
	{
		std::cout << score[i] << ", ";
	}

	// 더이상 필요 없을때는 반드시 제거 하세요
	delete[] score;

}
// 실행해서 9개 쯤 입력하고 -1 입력해 보세요







