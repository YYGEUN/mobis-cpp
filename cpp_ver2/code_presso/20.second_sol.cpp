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
    static AddressEntry entries[100];
    static int entryCount;

public:
    static void addEntry(const string& name, const int& age, const string& address) {
        if (entryCount < 100) {
            entries[entryCount++] = { name, age, address };
        }
        else {
            cout << "주소록이 꽉 찼습니다." << endl;
        }
    }

    static void printEntries() {
        for (int i = 0; i < entryCount; i++) {
            cout << "이름: " << entries[i].name << ", 나이: " << entries[i].age << ", 주소: " << entries[i].address << endl;
        }
    }
};
AddressEntry AddressBook::entries[100];
int AddressBook::entryCount=0;

int main() {
    /*AddressBook book;*/
    int choice;
    while (1) {
        cout << "메인 메뉴)\n";
        cout << "1.입력\n";
        cout << "2.출력\n";
        cout << "3.종료\n";
        cout << "번호를 입력하세요: ";
        cin >> choice;

        //switch (int choice = cin >> choice; choice) {
        //case 1:
        //    break;
        //}

        if (choice == 1) {
            string name, address;
            int age;
            cout << "이름: ";
            cin >> name;
            cout << "나이: ";
            cin >> age;
            cout << "주소: ";
            cin >> address;
            AddressBook::addEntry(name, age, address);
        }
        else if (choice == 2) {
            AddressBook::printEntries();
        }
        else if (choice == 3) {
            cout << "프로그램을 종료합니다.\n";
            break;
        }
        else {
            cout << "잘못된 선택입니다. 다시 시도해주세요.\n";
        }
    }

    return 0;
}



