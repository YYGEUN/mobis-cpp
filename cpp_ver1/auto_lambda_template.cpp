#include <iostream>
#include <initializer_list>

using namespace std;

//templete
template<typename t1, typename t2>
auto Plus(t1 t, t2 tt) -> decltype(t + tt)
{
	return t + tt;
}

template<typename t1, typename t2>
auto Minus(t1 t, t2 tt) -> decltype(t - tt)
{
	return t - tt;
}

//inline �Լ�
//��� �����Լ� (������ ���꿡 �̿�)
//�Լ� ȣ�� -> ���ñ���
//� ������ ����ϴ� �Լ��� �����Ѵٰ��� --> �Լ��� ȣ�� ������ ������ �߻��ϰԵǾ� ������ ��������߻�
//�ζ����Լ� ȣ��� ��� �������� �ذ�
//�Ϲ� �Լ��� ��� ���������� iline ��

//�����Ͻ� �Ű����� �߷��� �Ұ����ؼ� �����Ͽ���
//void outa(auto b) .....

//�������ϳ� ���δٸ� �Ű������� ���̳� ������� auto �� �޴°��� ������
auto testa(int a, float b) {
	return a + b;
}

//�����ȯ����
auto output1() -> double {
	return 3.33f;
}

struct sta {
	int a;
	int b;
};

int Accel(int i) {
	return i + 1;
}

int main() {
	// auto
	// Ÿ���߷��� �ڵ����� ����
	// �Լ����� �������ִ�

	auto io1 = output1;

	cout << io1() << endl;

	auto a = 8;
	auto c = "asda";
	auto& num = a;

	cout << num << endl;

	a = 5;

	cout << num << endl;

	//auto�� �߷� �Ұ�����
	//auto numb = { 7,2.3f };


	//���ٽ� -- �͸��Լ�
	auto lambdatest = [] {
		cout << "dddasd\n";
		};
	auto lambdatest2 = [](int a) {
		cout << a * 7 <<endl;
		};

	lambdatest();
	lambdatest2(3);


	sta* abc = new sta;
	abc->a = 1;
	abc->b = 2;

	auto bbc = abc;
	bbc->a = 77;
	bbc->b = 5;

	cout << abc->a << endl;
	
	string s1 = "sweet";
	string s2 = "home";

	cout << Plus(s1, s2) << endl;
	cout << Minus(3, -5) << endl;


	//������� �ݺ���
	int arr[5] = { 1,2,3 };
	for (int i : arr) {
		cout << i << endl;
	}

	if (int want = Accel(50); want <= 60) {
		cout << "ok" << endl;
	}

	

	return 0;
}