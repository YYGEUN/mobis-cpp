#include <iostream>

using namespace std;
// 객체 지향 --> 유지보수가 용이한 클래스 만드는 기법
//상속 -> 추상클래스,인터페이스
//has-a
// 
// 추상클래스 ---------------------------
//추상함수가 1개이상 --> 오버라이딩 의무적
//객체생성 불가

// 인터페이스 ---------------------------
//추상함수로만 이루어짐

// 폴리모피즘 : 객체의다양성
// 상위클래스의 포인터 변수는 하위클래스의 객체 주소를 받을수 있다.

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
	virtual void Sleep() = 0; // 추상함수,순수가상함수 : 런타임 바인딩 -- 실행시 함수 호출번지가 결정됨
	virtual void Eat() = 0; // 주소지가 나중에 결정되므로 자식 클래스의 eat 보다 주소가 늦게 할당됨
	void setpet(int n) { npet = n; }
};

class dog :public pet {
private:
	int ndog;
public:
	dog() { cout << "dog const call" << endl; }
	~dog() { cout << "dog dest call" << endl; }
	void Speak() { cout << "멍" << endl; }
	void setdog(int n) { ndog = n; }
	void setdog() { ndog = 20; }
	void Eat() { cout << "Bone" << endl; }
	void Sleep() { cout << "강잠" << endl; }
};

class cat :public pet {
private:
	int ncat;
public:
	cat() { cout << "cat const call" << endl; }
	~cat() { cout << "cat dest call" << endl; }
	void setdog(int n) { ncat = n; }
	void setdog() { ncat = 10; }
	void Speak() { cout << "야옹" << endl; }
	void Eat() { cout << "Fish" << endl; }
	void Sleep() { cout << "고잠" << endl; }
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
	
	//dog* dg = (dog*)pt; // 상위 클래스포인터를 하위클래스로 강제형변환은 타입 안정성 확인 필요하므로 아래 캐스팅 사용
	dog* dg = dynamic_cast<dog*>(pt);
	if (dg != NULL) {
		dg->setdog(11);
	}
	else {
		cout << "잘못된 형변환" << endl;
	}

	delete pt; // pet만 소멸 --> dog 살아있음 상위 클래스에서 virtual 소멸자를 사용하여 해결함



	return 0;
}