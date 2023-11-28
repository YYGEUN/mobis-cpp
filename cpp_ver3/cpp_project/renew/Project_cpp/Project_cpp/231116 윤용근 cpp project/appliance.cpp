#include "appliance.h"
#include "functions.h"
#include "msg.h"

SMSManager sms;

std::string BaseInfo::get_type()
{
    return type;
}
std::string BaseInfo::get_name()
{
    return name;
}
std::string BaseInfo::get_state1()
{
    return state1;
}
int BaseInfo::get_powerconsumtion()
{
    return powerconsumtion;
}
int BaseInfo::get_Use_H()
{
    return Use_H;
}
int BaseInfo::get_Start_H()
{
    return Start_H;
}
int BaseInfo::get_Power()
{
    return Power;
}
void BaseInfo::turn_on()
{
    if (Start_H == 0) {
        Start_H = Get_time();
    }
    Power = 1;
}
void BaseInfo::turn_off()
{
    if (Start_H != 0) {
        Use_H += Get_time() - Start_H;
        Start_H = 0;
    }
    Power = 0;
}
void BaseInfo::set_state1(std::string& s)
{
    state1 = s;
}
void BaseInfo::set_Use_H(time_t t)
{
    Use_H += t;
}
void BaseInfo::set_Strat_H(time_t t)
{
    Start_H = t;
}
void BaseInfo::set_PowerON()
{
    Power = 1;
}
void BaseInfo::set_PowerOFF()
{
    Power = 0;
}
void BaseInfo::save(std::ofstream* f)
{
    if (f->is_open()) {
        *f << type << std::endl << name << std::endl << state1 << std::endl << Power << std::endl
            << powerconsumtion << std::endl << Use_H << std::endl;
    }
    save_state(f);
}
void BaseInfo::save_state(std::ofstream* f)
{
    if (f->is_open()) {
        *f << type << std::endl << name << std::endl << state1 << std::endl << Power << std::endl
            << powerconsumtion << std::endl << Use_H << std::endl;
    }
}

void Aircon::set_temperature(int t)
{
    temperature = t;
}
void Aircon::Show()
{
    std::cout << "==========================================\n";
    std::cout << "제품 이름 : " << get_name() << std::endl;
    std::cout << "제품 타입 : " << get_type() << std::endl;
    if (get_Power() == 0) { std::cout << "전원 상태 : OFF" << std::endl; }
    else { std::cout << "전원 상태 : ON" << std::endl; }
    std::cout << "소비 전력 : " << get_powerconsumtion() << std::endl;
    std::cout << "현재 온도 : " << temperature << std::endl;
    std::cout << "사용 모드 : " << get_state1() << std::endl;
    if (get_Start_H() != 0) { std::cout << "사용 시간 : " << get_Use_H() + Get_time() - get_Start_H() << std::endl; }
    else { std::cout << "사용 시간 : " << get_Use_H() << std::endl; }
    std::cout << "==========================================\n";
}
void Aircon::Control()
{
    system("cls");
    std::cout << "==========================================\n";
    for (int i = 0; i < menuv.size(); i++) {
        std::cout << i + 1 << ". " << menuv[i] << std::endl;
    }
    std::cout << "==========================================\n";
    std::cout << "나가기 (Press 0)\n";
    std::cout << "\n▶ " << "번호 입력 : ";
    int cmd;
    while (checkint(&cmd, menuv.size(), "번호") == -1) {}

    if (cmd == 0) return;
    if (cmd == 1) { turn_on(); sms.Send_msg(get_type(), get_name(), "ON"); }
    else if (cmd == 2) { turn_off(); sms.Send_msg(get_type(), get_name(), "ON");; }
    else if (cmd == 3) {
        system("cls");
        std::cout << "==========================================\n";
        for (int i = 0; i < v.size(); i++) {
            std::cout << i + 1 << ". " << v[i] << std::endl;
        }
        std::cout << "==========================================\n";
        std::cout << "나가기 (Press 0)\n";
        std::cout << "\n▶ " << "번호 입력 : ";
        int cmd2;
        while (checkint(&cmd2, v.size(), "번호") == -1) {}
        if (cmd2 == 0) return;
        set_state1(v[cmd2 - 1]);
    }
    else if (cmd == 4) {
        int cmd2;
        std::cout << "==========================================\n";
        std::cout << "현재온도 : " << this->temperature << std::endl;
        std::cout << "==========================================\n";
        std::cout << "\n▶ 희망온도 입력 : ";
        while (1) {
            int temp = checkintonly(&cmd2, "희망온도");
            if (cmd2 == 0) {
                break;
            }

            if (temp == -1) {
                continue;
            }
            else if (temp > 40 || temp < 15) {
                std::cout << "온도 설정 범위내에서 입력해주세요 (15 ~ 40)" << std::endl;
                std::cout << "\n▶ " << "희망온도 입력 : ";
                continue;
            }
            break;
        }

        this->temperature = cmd2;
    }
}
void Aircon::save_state(std::ofstream* f)
{
    f->close();
}

void Washer::Control()
{
    system("cls");
    std::cout << "==========================================\n";
    for (int i = 0; i < menuv.size(); i++) {
        std::cout << i + 1 << ". " << menuv[i] << std::endl;
    }
    std::cout << "==========================================\n";
    std::cout << "나가기 (Press 0)\n";
    std::cout << "\n▶ " << "번호 입력 : ";
    int cmd;
    while (checkint(&cmd, menuv.size(), "번호") == -1) {}

    if (cmd == 0) return;
    if (cmd == 1) { turn_on(); sms.Send_msg(get_type(), get_name(), "ON"); }
    else if (cmd == 2) { turn_off(); sms.Send_msg(get_type(), get_name(), "ON");; }
    else if (cmd == 3) {
        system("cls");
        std::cout << "==========================================\n";
        for (int i = 0; i < v.size(); i++) {
            std::cout << i + 1 << ". " << v[i] << std::endl;
        }
        std::cout << "==========================================\n";
        std::cout << "나가기 (Press 0)\n";
        std::cout << "\n▶ " << "번호 입력 : ";
        int cmd2;
        while (checkint(&cmd2, v.size(), "번호") == -1) {}
        if (cmd2 == 0) return;
        set_state1(v[cmd2 - 1]);
    }
}
void Washer::Show()
{
    std::cout << "==========================================\n";
    std::cout << "제품 이름 : " << get_name() << std::endl;
    std::cout << "제품 타입 : " << get_type() << std::endl;
    if (get_Power() == 0) { std::cout << "전원 상태 : OFF" << std::endl; }
    else { std::cout << "전원 상태 : ON" << std::endl; }
    std::cout << "소비 전력 : " << get_powerconsumtion() << std::endl;
    std::cout << "사용 모드 : " << get_state1() << std::endl;
    if (get_Start_H() != 0) { std::cout << "사용 시간 : " << get_Use_H() + Get_time() - get_Start_H() << std::endl; }
    else { std::cout << "사용 시간 : " << get_Use_H() << std::endl; }
    std::cout << "==========================================\n";
}
void Washer::save_state(std::ofstream* f)
{
    f->close();
}

void Light::Control()
{
    system("cls");
    std::cout << "==========================================\n";
    for (int i = 0; i < menuv.size(); i++) {
        std::cout << i + 1 << ". " << menuv[i] << std::endl;
    }
    std::cout << "==========================================\n";
    std::cout << "나가기 (Press 0)\n";
    std::cout << "\n▶ " << "번호 입력 : ";
    int cmd;
    while (checkint(&cmd, menuv.size(), "번호") == -1) {}

    if (cmd == 0) return;
    if (cmd == 1) { turn_on(); sms.Send_msg(get_type(), get_name(), "ON"); }
    else if (cmd == 2) { turn_off(); sms.Send_msg(get_type(), get_name(), "ON");; }
}
void Light::Show()
{
    std::cout << "==========================================\n";
    std::cout << "제품 이름 : " << get_name() << std::endl;
    std::cout << "제품 타입 : " << get_type() << std::endl;
    if (get_Power() == 0) { std::cout << "전원 상태 : OFF" << std::endl; }
    else { std::cout << "전원 상태 : ON" << std::endl; }
    std::cout << "소비 전력 : " << get_powerconsumtion() << std::endl;
    if (get_Start_H() != 0) { std::cout << "사용 시간 : " << get_Use_H() + Get_time() - get_Start_H() << std::endl; }
    else { std::cout << "사용 시간 : " << get_Use_H() << std::endl; }
    std::cout << "==========================================\n";
}
void Light::save_state(std::ofstream* f)
{
    f->close();
}

void CooCoo::Control()
{
    system("cls");
    std::cout << "==========================================\n";
    for (int i = 0; i < menuv.size(); i++) {
        std::cout << i + 1 << ". " << menuv[i] << std::endl;
    }
    std::cout << "==========================================\n";
    std::cout << "나가기 (Press 0)\n";
    std::cout << "\n▶ " << "번호 입력 : ";
    int cmd;
    while (checkint(&cmd, menuv.size(), "번호") == -1) {}

    if (cmd == 0) return;
    if (cmd == 1) { turn_on(); sms.Send_msg(get_type(), get_name(), "ON"); }
    else if (cmd == 2) { turn_off(); sms.Send_msg(get_type(), get_name(), "ON");; }
    else if (cmd == 3) {
        system("cls");
        std::cout << "==========================================\n";
        for (int i = 0; i < v.size(); i++) {
            std::cout << i + 1 << ". " << v[i] << std::endl;
        }
        std::cout << "==========================================\n";
        std::cout << "나가기 (Press 0)\n";
        std::cout << "\n▶ " << "번호 입력 : ";
        int cmd2;
        while (checkint(&cmd2, v.size(), "번호") == -1) {}
        if (cmd2 == 0) return;
        set_state1(v[cmd2 - 1]);
    }
}
void CooCoo::Show()
{
    std::cout << "==========================================\n";
    std::cout << "제품 이름 : " << get_name() << std::endl;
    std::cout << "제품 타입 : " << get_type() << std::endl;
    if (get_Power() == 0) { std::cout << "전원 상태 : OFF" << std::endl; }
    else { std::cout << "전원 상태 : ON" << std::endl; }
    std::cout << "소비 전력 : " << get_powerconsumtion() << std::endl;
    std::cout << "사용 모드 : " << get_state1() << std::endl;
    if (get_Start_H() != 0) { std::cout << "사용 시간 : " << get_Use_H() + Get_time() - get_Start_H() << std::endl; }
    else { std::cout << "사용 시간 : " << get_Use_H() << std::endl; }
    std::cout << "==========================================\n";
}
void CooCoo::save_state(std::ofstream* f)
{
    f->close();
}
