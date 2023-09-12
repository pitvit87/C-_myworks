#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
	T date;
	Node<T>* next;
};

template< class T>
class Stack
{
private:
	Node<T>* head;
	unsigned int size;

	void Free()
	{
		Node<T>* p = head;

		while (p != nullptr)
		{
			head = head->next;
			delete p;
			p = head;
			//size--;
		}
		size = 0;
	}

	void Copy(Node<T>* _head)
	{
		if (_head == nullptr) return;

		Node<T>* p = _head;
		bool f_first = true;
		Node<T>* p2 = nullptr;
		Node<T>* p3 = nullptr;

		size = 0;

		while (p != nullptr)
		{
			p2 = new Node<T>;
			p2->date = p->date;
			p2->next = nullptr;
		
			if (f_first)
			{
				head = p2;
				p3 = p2;
				f_first = false;
			}
			else
			{
				p3->next = p2;
				p3 = p3->next;
			}
			size++;
			p = p->next;
		}
	}

public:
	Stack()
	{
		head = nullptr;
		size = 0;
	}

	void Push(T date)
	{
		if (size == 0)
		{
			head = new Node<T>;
			head->next = nullptr;
			head->date = date;
		}
		else
		{
			Node<T>* p = new Node<T>;
			p->date = date;
			p->next = head;
			head = p;
		}

		size++;
	}

	void Show(string msg)
	{
		Node<T>* p = head;
	
		cout << msg << " => ";

		while (p != nullptr)
		{
			cout << p->date << " ";
			p = p->next;
		}
		cout << endl;
	}

	~Stack()
	{
		Free();
	}

	T Pop()
	{
		if (size == 0)
			return 0;
	
		T item = head->date;

		Node<T>* p = head;

		head = head->next;

		delete p;

		size--;

		return item;
	}

	Stack(const Stack<T>& obj)
	{
		Copy(obj.head);
	}

	Stack<T>& operator=(const Stack<T>& obj)
	{
		if (size > 0)
			Free();
		Copy(obj.head);

		return *this;
	}

	unsigned int Size()
	{
		return size;
	}

};

int main()
{
	Stack<int> ST;

	ST.Push(10);
	ST.Push(20);
	ST.Push(30);
	ST.Show("ST");

	int t = ST.Pop();
	cout << "t = " << t << endl;
	ST.Show("ST");

	Stack<int> ST2 = ST;
	ST2 = ST;
	ST2.Show("ST2");
}
