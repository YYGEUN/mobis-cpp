#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next; //자신의 포인터 변수를 멤버로 가지는것 (자기참조 구조체)
};
class MyList {
private:
	Node* head;	Node* tail;
public:
	MyList() : head(0), tail(0) { }
	void Add(int data) {
		if (head == NULL) {
			head = tail = new Node;
		}
		else { tail = tail->next = new Node; }
		tail->data = data;		tail->next = 0;
	}
	void Show() {
		Node* cur = head;
		while (1) {
			cout << cur->data << endl;
			cur = cur->next;
			if (cur == NULL)
				break;
		}
	}
};
int main() {
	MyList list;
	list.Add(10);
	list.Add(20);
	list.Add(30);
	list.Show();


	return 0;
}


//Node* head;
//head = new Node;
//head->data = 10;
//head->next = new Node;
//head->next->data = 20;
//head->next->next = new Node;
//head->next->next->data = 30;
//head->next->next->next = 0;

//Node* cur = head;
//while(1)
//{
//	cout<< cur->data << endl;
//	cur = cur->next;
//	if( cur == NULL )
//		break;
//}




