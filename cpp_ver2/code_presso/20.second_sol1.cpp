#include <iostream>
#include <string>

using namespace std;

struct AddressEntry {
    string name;
    int age;
    string address;
};

class AddressBook {
private:
    //AddressEntry entries[100];
    AddressEntry* entries;
    int entryCount = 0;

public:
    AddressBook(int num) {
        entries = new AddressEntry[num];
    }
    ~AddressBook() {
        delete[] entries;
    }

    void addEntry(const string& name, const int& age, const string& address) {
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
    cout << "�Էµ����Ͱ���\n";
    int num;
    cin >> num;
    AddressBook book(num);
    int choice;
    while (1) {
        cout << "���� �޴�)\n";
        cout << "1.�Է�\n";
        cout << "2.���\n";
        cout << "3.����\n";
        cout << "��ȣ�� �Է��ϼ���: ";
        cin >> choice;

        //switch (int choice = cin >> choice; choice) {
        //case 1:
        //    break;
        //}

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



