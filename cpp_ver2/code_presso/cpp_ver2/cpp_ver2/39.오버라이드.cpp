#include <iostream>

using namespace std;
// ��ü ���� --> ���������� ������ Ŭ���� ����� ���
//��� -> �߻�Ŭ����,�������̽�
//has-a
// 
// �߻�Ŭ���� ---------------------------
//�߻��Լ��� 1���̻� --> �������̵� �ǹ���
//��ü���� �Ұ�

// �������̽� ---------------------------
//�߻��Լ��θ� �̷����

// ���������� : ��ü�Ǵپ缺
// ����Ŭ������ ������ ������ ����Ŭ������ ��ü �ּҸ� ������ �ִ�.

class IAnimal {
	virtual void Live() = 0;
	virtual void Die() = 0;
};

class pet {
private:
	int npet;
public:
	pet() { cout << "pet const call" << endl; }
	virtual ~pet() { cout << "pet dest call" << endl; }
	virtual void Sleep() = 0; // �߻��Լ�,���������Լ� : ��Ÿ�� ���ε� -- ����� �Լ� ȣ������� ������
	virtual void Eat() = 0; // �ּ����� ���߿� �����ǹǷ� �ڽ� Ŭ������ eat ���� �ּҰ� �ʰ� �Ҵ��
	void setpet(int n) { npet = n; }
};

class dog :public pet {
private:
	int ndog;
public:
	dog() { cout << "dog const call" << endl; }
	~dog() { cout << "dog dest call" << endl; }
	void Speak() { cout << "��" << endl; }
	void setdog(int n) { ndog = n; }
	void setdog() { ndog = 20; }
	void Eat() { cout << "Bone" << endl; }
	void Sleep() { cout << "����" << endl; }
};

class cat :public pet {
private:
	int ncat;
public:
	cat() { cout << "cat const call" << endl; }
	~cat() { cout << "cat dest call" << endl; }
	void setdog(int n) { ncat = n; }
	void setdog() { ncat = 10; }
	void Speak() { cout << "�߿�" << endl; }
	void Eat() { cout << "Fish" << endl; }
	void Sleep() { cout << "����" << endl; }
};

void PetEat(pet* pet) {
	pet->Eat();
}

void PetSetNum(pet* pet, int n) {
	pet->setpet(n);
}

int main()
{
	pet* pt = new dog;
	
	//dog* dg = (dog*)pt; // ���� Ŭ���������͸� ����Ŭ������ ��������ȯ�� Ÿ�� ������ Ȯ�� �ʿ��ϹǷ� �Ʒ� ĳ���� ���
	dog* dg = dynamic_cast<dog*>(pt);
	if (dg != NULL) {
		dg->setdog(11);
	}
	else {
		cout << "�߸��� ����ȯ" << endl;
	}

	delete pt; // pet�� �Ҹ� --> dog ������� ���� Ŭ�������� virtual �Ҹ��ڸ� ����Ͽ� �ذ���



	return 0;
}