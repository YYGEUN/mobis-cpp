#pragma once
#include "vehicle.h"

class horse :
    public Vehicle
{
public:
    virtual void Boarding(){ // ��ӽ� Virtual�� �⺻�Ӽ��̳� �⺻������ �������
        // virtual �Լ��� horse::Boarding �� ����� (vftable�� ����)
        // virtual �����̾����� �Լ��� ���� 2���� ����� --> �޸� ȿ���� ����
        cout << "No.1 ž��" << endl;
    }
};

class horse2 :
    public Vehicle
{
public:
    virtual void Boarding(){ // ��ӽ� Virtual�� �⺻�Ӽ��̳� �⺻������ �������
        // virtual �Լ��� horse2::Boarding �� �����  (vftable�� ����)
        // virtual �����̾����� �Լ��� ���� 2���� ����� --> �޸� ȿ���� ����
        cout << "No.2 ž��" << endl;
    }
};

class horse3 :
    public Vehicle
{
public:
    //virtual void Landing(){ // ��ӽ� Virtual�� �⺻�Ӽ��̳� �⺻������ �������
    //    // virtual �Լ��� horse3::bod �� ����� (vftable�� ����)
    //    // virtual �����̾����� �Լ��� ���� 2���� ����� --> �޸� ȿ���� ����
    //    cout << "No.3 ����" << endl;
    //}
    //virtual void Boarding() { // ��ӽ� Virtual�� �⺻�Ӽ��̳� �⺻������ �������
    //    // virtual �Լ��� horse3::bod �� ����� (vftable�� ����)
    //    // virtual �����̾����� �Լ��� ���� 2���� ����� --> �޸� ȿ���� ����
    //    cout << "No.3 ž��" << endl;
    //}
    virtual void run() { // ��ӽ� Virtual�� �⺻�Ӽ��̳� �⺻������ �������
        // virtual �Լ��� horse3::bod �� ����� (vftable�� ����)
        // virtual �����̾����� �Լ��� ���� 2���� ����� --> �޸� ȿ���� ����
        cout << "No.3 ���" << endl;
    }
    virtual void die() { // ��ӽ� Virtual�� �⺻�Ӽ��̳� �⺻������ �������
        // virtual �Լ��� horse3::bod �� ����� (vftable�� ����)
        // virtual �����̾����� �Լ��� ���� 2���� ����� --> �޸� ȿ���� ����
        cout << "No.3 ����" << endl;
    }
    virtual void respawned() { // ��ӽ� Virtual�� �⺻�Ӽ��̳� �⺻������ �������
        // virtual �Լ��� horse3::bod �� ����� (vftable�� ����)
        // virtual �����̾����� �Լ��� ���� 2���� ����� --> �޸� ȿ���� ����
        cout << "No.3 ������" << endl;
    }
};

class Move :
    public horse3
{
public:
    void summon() { // ��ӽ� Virtual�� �⺻�Ӽ��̳� �⺻������ �������
        // virtual �Լ��� horse3::bod �� ����� (vftable�� ����)
        // virtual �����̾����� �Լ��� ���� 2���� ����� --> �޸� ȿ���� ����
        cout << "��ȯ" << endl;
    }
};
