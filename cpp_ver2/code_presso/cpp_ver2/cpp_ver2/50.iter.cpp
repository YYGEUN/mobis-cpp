#include <iostream>

using namespace std;

template<class T>
class slist
{
private:
	struct Node {
		T		data;
		Node* next;
		Node(T d, Node* n) : data(d), next(n) {}
	};
	Node* head;
public:
	slist() : head(0) {}
	~slist() { while (!head) pop_front(); }
	void push_front(T d)
	{
		head = new Node(d, head);
	}
	T pop_front() {
		T ret = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		return ret;
	}
	//slist<int>::iterator p = s.begin();
	class iterator {
		Node* current;
	public:
		iterator(Node* init = 0) : current(init) {} // 안들어왔을때만 0으로 나머지는 init 값으로 초기화시킴

		iterator& operator++() {
			current = ((current == 0) ?
				0 : current->next);
			return *this;
		}
		T& operator*()
		{
			return current->data;
		}
		bool operator != (const iterator& i)
		{
			return (current != i.current);
		}
	};
	friend class iterator;

	iterator begin()
	{
		return iterator(head);
	}
	iterator end() {
		return iterator();
	}
};


template<class T1, class T2>
T1 find(T1 begin, T1 end, T2 value)
{
	while (begin != end && *begin != value)
		++begin;

	return begin;
}

void main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

	slist<int>::iterator p = s.begin();

	while (p != s.end())
	{
		cout << *p << endl; // operator 연산자로 감
		++p; // operator 연산자로 감
	}

	//slist<int>::iterator b = s.begin();
	//slist<int>::iterator e = s.end();
	//slist<int>::iterator res = find(b, e, 20);

	//cout << *res << endl;
}
