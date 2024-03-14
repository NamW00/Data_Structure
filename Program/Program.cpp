#include <iostream>

using namespace std;

template <typename T>
class DoubleLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};

	int size;
	Node* head;
	Node* tail;

public:
	DoubleLinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void PushFront(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		newNode->next = nullptr;

		newNode->prev = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
			// tail = head = newNode;
		}
		else
		{
			// 1. newNode의 next가 head를 가리키게 합니다.
			newNode->next = head;

			// 2. head의 prev가 newNode를 가리키게 합니다.
			head->prev = newNode;

			// 3. head가 newNode를 가리키게 합니다.
			head = newNode;
		}
		size++;
	}

	void PushBack(T data)
	{
		Node* newNode = new Node;
		
		newNode->data = data;
		
		newNode->next = nullptr;
		
		newNode->prev = nullptr;

		if (tail == nullptr)
		{
			tail = newNode;
			head = newNode;
			// tail = head = newNode;
		}
		else
		{
			// 1. newNode의 prev가 tail을 가리키게 합니다.
			newNode->prev = tail;

			// 2. tail의 next가 newNode를 가리키게 합니다.
			tail->next = newNode;

			// 3. tail이 newNode를 가리키게 합니다.
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

	void PopBack()
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
			deleteNode = tail;
			tail = deleteNode->prev;
			delete deleteNode;
		}
		size--;
	}
	void Show()
	{
		Node* showNode = head;
		cout << "Double Linked list (Show) : ";
		while (showNode != nullptr)
		{
			cout << showNode->data << " ";
			showNode = showNode->next;
		}
		cout << endl;
	}

	void ReverseShow()
	{
		Node* showNode = tail;
		cout << "Double Linked list (Reverse Show) : ";
		while (showNode != nullptr)
		{
			cout << showNode->data << " ";
			showNode = showNode->prev;
		}
		cout << endl;
	}

	int Size()
	{
		return size;
	}
};

int main()
{
	DoubleLinkedList<int> DoubleLinkedList;

	DoubleLinkedList.PushFront(100);
	DoubleLinkedList.Show();

	DoubleLinkedList.PushFront(99);
	DoubleLinkedList.Show();

	DoubleLinkedList.PushBack(98);
	DoubleLinkedList.Show();

	DoubleLinkedList.Show();
	DoubleLinkedList.ReverseShow();




	return 0;
}