#include <iostream>
#include <string>
#include <conio.h>

// 객체지향 프로그램은 모든 것을 "객체" 화 하는 것입니다.

// 1. "Validation 정책" 자체를 클래스로 설계 합니다.
// 2. 그런데, Edit 에서는 다양한 정책을 교체 하면서 사용해야 합니다.
//    => 인터페이스를 설계 합니다.

struct IValidator 
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true;}
	virtual ~IValidator() {}
};

// 주민 등록 번호 : 901   1     확인
// validate    : "901" 까지 입력 했는데, 추가로 1이 들어 온 경우 입력 받아도 되는지를 판단하는 함수 - 입력받아도 됩니다.
// is_complete : 입력이 완료 되어 확인 버튼을 누를수 있는지 확인하는 함수 - 주민번호 13 자리 입력이 완료된것은 아닙니다.


class Edit
{
	std::string data;

	IValidator* val = nullptr; // 입력값의 유효성을 검증할때 사용할 객체
public:
	void set_validator(IValidator* p) { val = p;}

	// 핵심 : 아래 코드에서 val 를 사용하는 부분을 보세요
	std::string get_text()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13 && ( val == nullptr || val->is_complete(data)  ) ) break; 

			if ( val == nullptr || val->validate(data, c) )	
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
	// Edit 를 만들고 validator 라는 것을 연결하지 않았습니다.
	// 아래 Edit 는 모든 문자가 입력 됩니다.
	// 실제 Validator 만드는 코드는 다음 소스를 보세요
	Edit edit;

	while (1)
	{
		std::string s = edit.get_text();
		std::cout << s << std::endl;
	}
}
