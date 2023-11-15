#include <vector>
#include <string>
#include <map>
#include <iostream>

class SMSManager
{
	using PHONENUMBER = std::string;

	std::map<std::string, std::vector<PHONENUMBER>> m;
public:
	void add_sms_number(const std::string& key, const PHONENUMBER& number) 
	{
		m[key].push_back(number); 
	}

	// #. 이전 버전에서 이 함수 부분만 변경했습니다.
	void send_sms(const std::string& key, const std::string& msg)
	{
//		auto& v = m[key]; // 기본 코드

		// 변경된 코드
		auto it = m.find(key);

		if ( it != m.end() )
		{
			for( const PHONENUMBER& number : it->second )
			{
				std::cout << number << " : " << msg << std::endl;
			}
		}		
	}
};

SMSManager sms;

int main()
{	
	sms.add_sms_number("TV_POWER_ON", "010-111-2222");
	sms.add_sms_number("TV_POWER_ON", "010-111-3333");
	sms.add_sms_number("RADIO_POWER_ON", "010-111-2222");

	sms.send_sms("TV_POWER_ON", 		// 키값
				 "TV 가 켜졌습니다.");		// 전송할 문자열
}