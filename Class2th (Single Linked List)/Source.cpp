#include <iostream>

using namespace std;


template <typename T>
class SingleLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	Node* head;
	Node* tail;

	int size;

public:
	SingleLinkedList()
	{
		head = nullptr;
		tail = nullptr;

		size = 0;
	}

	void PushFront(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		newNode->next = nullptr;

		if (head == nullptr && tail == nullptr)
		{
			tail = newNode;
			head = newNode;
			// tail = head = newNode;
		}
		else
		{
			newNode->next = head;

			head = newNode;
		}
		size++;
	}

	void PushBack(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		newNode->next = nullptr;

		if (head == nullptr && tail == nullptr)
		{
			tail = newNode;
			head = newNode;
			// tail = head = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}
	void PopFront()
	{
		// size = 0 일때 : 원래 노드가 없으므로 return을 해주면 된다.
		if (size == 0)
		{
			cout << "List is empty" << endl;
			return;
		}

		// size = 1 일때 : Node * deleteNode생성 후 deleteNode해당 노드를 삭제한후 head와 tail을 nullptr로 만들어준다. size--;
		// size = 2 이상일때 : Node * deleteNode생성 후 head포인터를 head->next위치로 옮겨준다. size--;

		Node* deleteNode = nullptr;

		if (size == 1)
		{
			deleteNode = head;
			head = nullptr;
			tail = nullptr;
			delete deleteNode;

		}
		else
		{
			deleteNode = head;
			head = deleteNode->next;
			delete deleteNode;
		}
		size--;
	}
	// void PopBack()
	// {
	// 	// size = 0 일때 : 원래 노드가 없으므로 return을 해주면 된다.
	// 	if (size == 0)
	// 	{
	// 		cout << "List is empty" << endl;
	// 		return;
	// 	}
	// 
	// 	// size = 1 일때 : Node * deleteNode생성 후 deleteNode해당 노드를 삭제한후 head와 tail을 nullptr로 만들어준다. size--;
	// 	// size = 2 이상일때 : Node * deleteNode생성 후 head포인터를 head->next위치로 옮겨준다. size--;
	// 
	// 	Node* deleteNode = tail;
	// 
	// 	if (size == 1)
	// 	{
	// 		deleteNode = tail;
	// 		head = nullptr;
	// 		tail = nullptr;
	// 		delete deleteNode;
	// 
	// 	}
	// 	else
	// 	{
	// 		deleteNode = tail;
	// 		tail = deleteNode;
	// 		delete deleteNode;
	// 	}
	// 	size--;
	// }

	void Show()
	{
		Node* showNode = head;
		while (showNode != nullptr)
		{
			cout << showNode->data << endl;
			showNode = showNode->next;
		}

	}

	int Size()
	{
		return size;
	}

	~SingleLinkedList()
	{
		while (size != 0)
		{
			PopFront();
		}
	}

};

int main()
{
	SingleLinkedList<int> SingleLinkedList;

	SingleLinkedList.PushFront(100);
	SingleLinkedList.PushFront(99);
	SingleLinkedList.PushBack(98);

	cout << "Single Linked List의 크기 : " << SingleLinkedList.Size() << endl;
	SingleLinkedList.Show();

	cout << endl;

	SingleLinkedList.PopFront();
	cout << "Single Linked List의 크기 : " << SingleLinkedList.Size() << endl;
	SingleLinkedList.Show();

	cout << endl;

	SingleLinkedList.PopFront();
	cout << "Single Linked List의 크기 : " << SingleLinkedList.Size() << endl;
	SingleLinkedList.Show();

	cout << endl;

	SingleLinkedList.PopFront();
	cout << "Single Linked List의 크기 : " << SingleLinkedList.Size() << endl;
	SingleLinkedList.Show();

	return 0;
}