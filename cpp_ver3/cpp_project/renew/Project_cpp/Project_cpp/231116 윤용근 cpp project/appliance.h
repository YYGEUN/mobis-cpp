#pragma once
#include <iostream>
#include <map>
#include <functional>
#include <memory>
#include <fstream>
#include <vector>

//가전의 기본 정보등이 담긴 기반 클래스
class BaseInfo
{
private:
	std::string name; // 가전 이름
	std::string type; // 가전 타입
	std::string state1; // 가전 상태 ex) 건조, 냉방 등...
	int Power; // 전원 상태 0-->OFF 1-->ON
	int powerconsumtion; // 전력소비량
	time_t Use_H; // 사용시간
	time_t Start_H; // 사용 시작시간
public:
	// 기본 생성자
	BaseInfo(const std::string s, int cmd, const std::string& type)
		:Power(0), state1("대기중"), Use_H(0), Start_H(0), name(s), type(type), powerconsumtion(cmd) {}

	// 로드시 사용되는 생성자
	BaseInfo(const std::string s, int cmd, const std::string& type, int power, int use_h)
		:Power(power), state1("대기중"), Use_H(use_h), Start_H(0), name(s), type(type), powerconsumtion(cmd) {}

	std::string get_type();
	std::string get_name();
	std::string get_state1();
	int get_powerconsumtion();
	int get_Use_H();
	int get_Start_H();
	int get_Power();
	
	// 전원켜고 Start_H 갱신
	void turn_on();
	// 전원끄고 Use_H 갱신
	void turn_off();

	void set_state1(std::string& s);
	void set_Use_H(time_t t);
	void set_Strat_H(time_t t);
	void set_PowerON();
	void set_PowerOFF();

	void save(std::ofstream* f);

	// 각 가전의 컨트롤 함수에 오버라이드 (가상함수)
	virtual void Control() = 0;

	// 각 가전의 정보보기(SHOW) 함수에 오버라이드 (가상함수)
	virtual void Show() = 0;

	// 각 가전의 저장(SAVE) 함수에 오버라이드 (가상함수)
	virtual void save_state(std::ofstream* f);

	virtual ~BaseInfo() {}
};

// 가전 에어컨 클래스
class Aircon : public BaseInfo
{
	// 에어컨 상태 저장 벡터 
	std::vector<std::string> v = { "제습","냉방","난방" };
	// 에어컨 메뉴 저장 벡터
	std::vector<std::string> menuv = { "전원 ON","전원 OFF","에어컨 모드","온도 설정" };
	int temperature;
public:
	//에어컨 기본생성자
	Aircon(const std::string& s, const int pc, const std::string& type) :BaseInfo(s, pc, type), temperature(25) {}
	//로드시 에어컨 생성자
	Aircon(const std::string& s, const int pc, const std::string& type, int power, int use_h) :BaseInfo(s, pc, type, power, use_h), temperature(25) {}
	
	void set_temperature(int t);
	
	// 에어컨 정보 출력
	void Show() override;
	// 메뉴저장 벡터를 불러오고 선택에 따른 상태 변경 함수
	void Control() override;
	// 에어컨의 추가 정보 세이브
	void save_state(std::ofstream* f) override;
};
// 가전 세탁기 클래스
class Washer : public BaseInfo
{
	std::vector<std::string> v = { "건조","일반세탁","빠른세탁" };
	std::vector<std::string> menuv = { "전원 ON","전원 OFF","세탁기 모드" };
public:
	//세탁기 기본생성자
	Washer(const std::string& s, const int pc, const std::string& type) :BaseInfo(s, pc, type) {}
	//로드시 세탁기 생성자
	Washer(const std::string& s, const int pc, const std::string& type, int power, int use_h) :BaseInfo(s, pc, type, power, use_h) {}
	// 세탁기 정보 출력
	void Control() override;
	// 메뉴저장 벡터를 불러오고 선택에 따른 상태 변경 함수
	void Show() override;
	// 세탁기 추가 정보 세이브
	void save_state(std::ofstream* f) override;
};
// 가전 전등 클래스
class Light : public BaseInfo
{
	std::vector<std::string> menuv = { "전원 ON","전원 OFF" };
public:
	//전등 기본생성자
	Light(const std::string& s, const int pc, const std::string& type) :BaseInfo(s, pc, type) {}
	//로드시 전등 생성자
	Light(const std::string& s, const int pc, const std::string& type, int power, int use_h) :BaseInfo(s, pc, type, power, use_h) {}
	// 전등 정보 출력
	void Control() override;
	// 메뉴저장 벡터를 불러오고 선택에 따른 상태 변경 함수
	void Show() override;
	// 전등 추가 정보 세이브
	void save_state(std::ofstream* f) override;
};
// 가전 쿠쿠 클래스
class CooCoo : public BaseInfo
{
	std::vector<std::string> v = { "현미","백미","누룽지" };
	std::vector<std::string> menuv = { "전원 ON","전원 OFF","쿠쿠 모드"};
public:
	//쿠쿠 기본생성자
	CooCoo(const std::string& s, const int pc, const std::string& type) :BaseInfo(s, pc, type) {}
	//로드시 쿠쿠 생성자
	CooCoo(const std::string& s, const int pc, const std::string& type, int power, int use_h) :BaseInfo(s, pc, type, power, use_h) {}
	// 쿠쿠 정보 출력
	void Control() override;
	// 메뉴저장 벡터를 불러오고 선택에 따른 상태 변경 함수
	void Show() override;
	// 쿠쿠 추가 정보 세이브
	void save_state(std::ofstream* f) override;
};
