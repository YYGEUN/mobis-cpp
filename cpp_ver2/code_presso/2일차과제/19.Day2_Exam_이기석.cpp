#include <iostream>
#include <string>

using namespace std;

class AddressBook {
private:
    struct AddressEntry {
        string name;
        int age;
        string address;
    };

    AddressEntry entries[100];
    int entryCount = 0;

public:
    void addEntry(const string& name, int age, string& address) {
        if (entryCount < 100) {
            entries[entryCount++] = { name, age, address };
        }
        else {
            cout << "�ּҷ��� �� á���ϴ�." << endl;
        }
    }

    void printEntries() const {
        for (int i = 0; i < entryCount; i++) {
            cout << "�̸�: " << entries[i].name << ", ����: " << entries[i].age << ", �ּ�: " << entries[i].address << endl;
        }
    }
};

int main() {
    AddressBook book;
    int choice;
    while (1) {
        cout << "���� �޴�)\n";
        cout << "1.�Է�\n";
        cout << "2.���\n";
        cout << "3.����\n";
        cout << "��ȣ�� �Է��ϼ���: ";
        cin >> choice;

        if (choice == 1) {
            string name, address;
            int age;
            cout << "�̸�: ";
            cin >> name;
            cout << "����: ";
            cin >> age;
            cout << "�ּ�: ";
            cin >> address;
            book.addEntry(name, age, address);
        }
        else if (choice == 2) {
            book.printEntries();
        }
        else if (choice == 3) {
            cout << "���α׷��� �����մϴ�.\n";
            break;
        }
        else {
            cout << "�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n";
        }
    } 


    return 0;
}



