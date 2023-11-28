#pragma once
#include "menu.h"
#include "appliance.h"

// 홈오토메이션 클래스
class HomeAutomationSystem
{
	std::vector<BaseInfo*> v; // 제품을 보관할 vector
	std::map<std::string, std::vector<std::shared_ptr <BaseInfo>>> vm; //key값은 제품 종류 value는 Baseinfo로 생성된 가전들
	std::map<std::string, int> namem; //중복이름 처리
	std::map<std::string, int> costm; //삭제된 가전제품들 비용저장 --> 제품타입에 대해서 분류하고 저장함
	std::vector<std::string> typev = { "세탁기","에어컨","쿠쿠","전등" }; // 제품 타입 벡터
public:
	HomeAutomationSystem() { init_menu(); }
	// 홈오토메이션 실행시 초기 설정값 
	void init_menu();
	// 홈오토메이션 실행시 저장된 자료가 있으면 불러오기 --> 불러오고난 파일은 삭제
	void Road();
	// 일시 정지 --> 제품들을 종료시키지않고 현재 상태 그대로 저장, (홈오토메이션 시작시 이전상태에 이어서 시작됨)
	void Go_OUT() ;
	// 종료 --> 제품들을 종료시키고 저장, (홈오토메이션 시작시 OFF 된상태로 초기화)
	void Shut_Down();
	// 현재 등록된 제품들을 팝업 시키고 유저의 메뉴선택에 따라 처리함수로 보내줌
	void Create_List(int casenum);
	// 전부 종료
	void All_PowerOFF();
	// 전부 켜기
	void All_PowerON();
	// 제품 추가 --> 초기설정된 제품목록들이 뜨고 선택시 해당하는 제품의 필수정보를 입력받아서 생성
	void add_product(int n);
	// 제품 삭제 --> use_h 갱신 , costm 갱신 후 삭제
	void delete_product(int idx, const std::string s, std::shared_ptr <TempMenu> pm);
	// 제품 정보 출력 --> 각 가전의 show함수로 연결
	void show_product(int idx, const std::string s, std::shared_ptr <TempMenu> pm);
	// 제품 제어 --> 각 가전의 control함수로 연결
	void control_product(int idx, const std::string s, std::shared_ptr <TempMenu> pm);

	// 종료 선택시 가전을 종료시키고 사용 요금 출력
	void show_rate();
	// 현재 시간을 기준으로 사용 요금 출력 -- 갱신기능
	void calculate_rate();
	// 유저 관리 메뉴 --> 생성 및 삭제
	void Create_User_Menu();
};