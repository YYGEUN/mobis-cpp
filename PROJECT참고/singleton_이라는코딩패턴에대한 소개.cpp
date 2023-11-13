#include <iostream>

// singleton1.cpp
// 싱글톤 패턴에 대한 소개 입니다.
// 싱글톤 패턴 : 오직 한개의 객체만 존재하고 
//            프로그램의 어디에서도 동일한 방법으로 접근하게 할때 사용합니다

class SMSManager
{
public:
	static SMSManager& get_instance()
	{
		// 아래 객체는 이 함수가 최초 호출될때 생성되고
		// 프로그램 종료시 까지 항상 메모리에 존재합니다.
		// 어디서든 오직 한개의 이 객체에 접근하려면 get_instance() 를 호출하세요
		static SMSManager sms; 
		return sms;
	}
	void add_sms_number(const std::string& number)
	{
		std::cout << number << "등록" << std::endl;
	}
};
//==========
void f1()
{
	SMSManager& sms = SMSManager::get_instance();
	sms.add_sms_number("111");
}

int main()
{
	// 아래 처럼 어디에서든 "SMSManager::get_instance()" 를 호출하면
	// sms 객체의 참조를 얻을수 있습니다.
	f1();

	SMSManager& sms = SMSManager::get_instance();
	sms.add_sms_number("222");

}

