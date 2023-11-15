#include <iostream>
#include <string>
#include <conio.h>

// Edit : GUI 라이브러리의 EditBox(TextBox) 같은 클래스를 흉내내어서 만들었습니다.
//        실행해 보면 문자 입력은 안되고 숫자 입력만 가능합니다.
//        실행해서 숫자 몇개를 입력하고 enter 를 눌러 보세요		 

class Edit
{
	std::string data;
public:
	std::string get_text()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; // enter 키

			if ( isdigit(c) )	// 숫자일 때만 data 에 추가!
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

int main()
{
	Edit edit;
	while (1)
	{
		// edit 에 입력된 것을 꺼내와서 화면에 출력
		std::string s = edit.get_text();
		std::cout << s << std::endl;
	}
}
// 생각해 볼문제.. 
// 1. 위 Edit 는 사용자 입력중에 "숫자" 만을 입력 받고 있습니다. 
// => "나이"등을 입력 받을때 유용합니다.

// 2. 그런데, 이름을 입력받고자 한다면 "문자"도 입력 가능해야 합니다.
// => 즉, Edit 의 입력값에 대한 유효성 검사(Validation) 기능은 변경가능해야 합니다.
// => 23 번째 줄을 변경하면 되긴 합니다.!!

// 3. 그런데, 아래 생각을 해보세요
// => Edit 같은 클래스는 라이브러리의 내부에 존재하게 됩니다.
// => Validation 정책을 변경하기위해 라이브러리 내부 코드를 변경할수는 없습니다.

// 도전 과제
// => 여러분이 라이브러리 설계자라고 생각해 보세요
// => Edit 클래스의 사용자가 Validation 정책을 변경할수 있도록 디자인 해보세요 ( Edit 를 다시 만들라는 의미 )
// => 단, Edit 사용자는 Edit 자체의 코드를 변경하면 안됩니다.
