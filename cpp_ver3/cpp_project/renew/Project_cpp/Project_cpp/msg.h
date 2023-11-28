#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

// 메신저 클래스
class SMSManager
{
	//유저명 중복 검사 dictionary
	std::map<std::string, int> userm;
	//상태값을 key값으로 가지고 벡터에 저장된 유저들을 value로 갖는 dictionary --> key신호시 등록된 유저들에게 메세지보낼때 사용
	std::map<std::string, std::vector<std::string>> m;
public:
	// 유저등록
	void Add_User();
	// 유저삭제
	void Delete_User();
	// 등록된 유저에게 메세지 보냄
	void Send_msg(const std::string& machine, const std::string& name, const std::string& state);
	// HomeAutomaiton 종료 혹은 일시정시 시 usr.txt에 유저저장
	void save_user(std::ofstream* ou);
	// HomeAutomaiton 실행시 user.txt 에서 등록된 유저를 불러옴 --> 불러오고난 파일은 삭제
	void Road();
};