#include <iostream>
#include <string>
#include <conio.h>



struct IValidator 
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true;}
	virtual ~IValidator() {}
};

class Edit
{
	std::string data;

	IValidator* val = nullptr; 
public:
	void set_validator(IValidator* p) { val = p;}

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

// 이제 다양한 validation 정책을 가지는 "정책 클래스" 를 설계 하세요
class LimitDigitValidator : public IValidator 
{
	int value;
public:
	LimitDigitValidator(int n) : value(n) {}

	bool validate(const std::string& s, char c) override 
	{
		return isdigit(c) && s.size() < value;
	}	
};


int main()
{

	// 1. edit 를 만들고
	Edit edit;

	// 2. edit 가 사용할 정책을 연결합니다.
	LimitDigitValidator v(5); // 5자리이하 숫자만 입력 가능한 validator
	edit.set_validator(&v);   // edit 의 유효성 검사를 v 에 의존 합니다.

	while (1)
	{
		std::string s = edit.get_text();
		std::cout << s << std::endl;
	}
}

// 위와 같이 edit 같은 객체가 사용하는 알고리즘을 "별도의 객체로 만들어서 실행시간에 교체" 가능하게 하는 디자인 기법을
// "strategy(전략 패턴)" 이라고 합니다.

// 도전 과제 : 위 코드는 5자리이하의 숫자만 입력 됩니다.
//           "123" 처럼 3자만 입력해도 enter가 됩니다.
//           회사 사번이 5자리 숫자라면 "반드시 5자리를 입력해야 enter" 가 되게 하는 것이 좋습니다.
//           ==> 5자리까지 입력한 경우만 enter 가 되게 "LimitDigitValidator"를 수정해 보세요