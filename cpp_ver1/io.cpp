#include <iostream>

using namespace std;

int main() {

	const char* a = "aaaaa";
	int num;

	while (1) {
		cin >> num;
		//���� �ڷ����� �����ʴ��Է°��ϋ� �����÷ο����� ����ó��
		if (cin.fail() == true) {
			//�Էµ� ������ �켱 �ʱ�ȭ
			cin.clear();
			//�Էµ� ���۰��� ��� --> ���๮�ڸ� ������ ����
			cin.ignore(10, '\n'); // == cin.ignore()
		}
		cout << num << "\n";
	}


	return 0;
}