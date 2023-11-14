#include <vector>
#include <string>
#include <map>
#include <iostream>

// 1. main 함수에 있는 코드를 보고 사용법을 먼저 익히세요
// 2. 그리고 이 클래스의 소스를 생각해 보세요

class SMSManager
{
	using PHONENUMBER = std::string;

	std::map<std::string, std::vector<PHONENUMBER>> m;
public:
	void add_sms_number(const std::string& key, const PHONENUMBER& number) 
	{
		m[key].push_back(number); 
	}

	void send_sms(const std::string& key, const std::string& msg)
	{
		auto& v = m[key]; // v 는 vector 입니다.

		for( const PHONENUMBER& number : v )
		{
			std::cout << number << " : " << msg << std::endl;
		}		
	}
};

// 3. Project 에 도입하려면 아래 처럼 전역변수로 한개 만들어 놓고
//    main 의 코드를 보고 잘 활용해 보세요
SMSManager sms;

int main()
{	
	// STEP 1. event 에 대응 하는 함수를 등록합니다.
	// 1번째 인자 : 이벤트 종류를 나타내는 키값. 여러분이 정하세요
	// #1. TV 가 켜지면 2곳으로 알려 달라는 의미
	sms.add_sms_number("TV_POWER_ON", "010-111-2222");
	sms.add_sms_number("TV_POWER_ON", "010-111-3333");

	// #2. RADIO 가 켜지면 1곳으로 알려 달라는 의미
	sms.add_sms_number("RADIO_POWER_ON", "010-111-2222");

	// STEP 2. 이제 해당하는 이벤트가 발생하면 sms 객체의 멤버 함수를 사용해서
	//         등록된 번호에 SMS 문자를 전송합니다.
	sms.send_sms("TV_POWER_ON", 		// 키값
				 "TV 가 켜졌습니다.");		// 전송할 문자열
}

