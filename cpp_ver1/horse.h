#pragma once
#include "vehicle.h"

class horse :
    public Vehicle
{
public:
    virtual void Boarding(){ // 상속시 Virtual은 기본속성이나 기본적으로 명시해줌
        // virtual 함수로 horse::Boarding 이 선언됨 (vftable에 선언)
        // virtual 선언이없으면 함수가 따로 2개가 선언됨 --> 메모리 효율이 낮음
        cout << "No.1 탑승" << endl;
    }
};

class horse2 :
    public Vehicle
{
public:
    virtual void Boarding(){ // 상속시 Virtual은 기본속성이나 기본적으로 명시해줌
        // virtual 함수로 horse2::Boarding 이 선언됨  (vftable에 선언)
        // virtual 선언이없으면 함수가 따로 2개가 선언됨 --> 메모리 효율이 낮음
        cout << "No.2 탑승" << endl;
    }
};

class horse3 :
    public Vehicle
{
public:
    //virtual void Landing(){ // 상속시 Virtual은 기본속성이나 기본적으로 명시해줌
    //    // virtual 함수로 horse3::bod 이 선언됨 (vftable에 선언)
    //    // virtual 선언이없으면 함수가 따로 2개가 선언됨 --> 메모리 효율이 낮음
    //    cout << "No.3 하차" << endl;
    //}
    //virtual void Boarding() { // 상속시 Virtual은 기본속성이나 기본적으로 명시해줌
    //    // virtual 함수로 horse3::bod 이 선언됨 (vftable에 선언)
    //    // virtual 선언이없으면 함수가 따로 2개가 선언됨 --> 메모리 효율이 낮음
    //    cout << "No.3 탑승" << endl;
    //}
    virtual void run() { // 상속시 Virtual은 기본속성이나 기본적으로 명시해줌
        // virtual 함수로 horse3::bod 이 선언됨 (vftable에 선언)
        // virtual 선언이없으면 함수가 따로 2개가 선언됨 --> 메모리 효율이 낮음
        cout << "No.3 출발" << endl;
    }
    virtual void die() { // 상속시 Virtual은 기본속성이나 기본적으로 명시해줌
        // virtual 함수로 horse3::bod 이 선언됨 (vftable에 선언)
        // virtual 선언이없으면 함수가 따로 2개가 선언됨 --> 메모리 효율이 낮음
        cout << "No.3 죽음" << endl;
    }
    virtual void respawned() { // 상속시 Virtual은 기본속성이나 기본적으로 명시해줌
        // virtual 함수로 horse3::bod 이 선언됨 (vftable에 선언)
        // virtual 선언이없으면 함수가 따로 2개가 선언됨 --> 메모리 효율이 낮음
        cout << "No.3 리스폰" << endl;
    }
};

class Move :
    public horse3
{
public:
    void summon() { // 상속시 Virtual은 기본속성이나 기본적으로 명시해줌
        // virtual 함수로 horse3::bod 이 선언됨 (vftable에 선언)
        // virtual 선언이없으면 함수가 따로 2개가 선언됨 --> 메모리 효율이 낮음
        cout << "소환" << endl;
    }
};
