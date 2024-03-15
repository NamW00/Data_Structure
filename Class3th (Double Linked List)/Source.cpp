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
	int position;
	Node* head;
	Node* tail;

public:
	DoubleLinkedList()
	{
		size = 0;
		position = 0;
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

		Node* deleteNode = head;

		if (size == 1)
		{
			head = nullptr;
			tail = nullptr;
			delete deleteNode;

		}
		else
		{
			head = deleteNode->next;
			head->prev = nullptr;
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

		Node* deleteNode = tail;

		if (size == 1)
		{
			head = nullptr;
			tail = nullptr;

			delete deleteNode;

		}
		else
		{
			deleteNode = tail;

			tail = deleteNode->prev;

			tail->next = nullptr;

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

	void Insert(int position, T data)
	{
		if (size + 1 < position)
		{
			cout << "The Size is out of bounds" << endl;
			return;
		}

		if (position <= 1)
		{
			PushFront(data);
			return;
		}
		else if (position == size + 1)
		{
			PushBack(data);
			return;
		}

		Node* currentNode = head;

		for (int i = 1; i < position; i++)
		{
			currentNode = currentNode->next;
		}

		Node* newNode = new Node;

		newNode->data = data;

		newNode->next = currentNode;

		currentNode->prev->next = newNode;

		newNode->prev = currentNode->prev;

		currentNode->prev = newNode;

		size++;
	}

	int Size()
	{
		return size;
	}

	~DoubleLinkedList()
	{
		while (size != 0)
		{
			PopBack();
		}
	}
};

int main()
{
	DoubleLinkedList<int> DoubleLinkedList;

	// DoubleLinkedList.PushFront(100);
	// cout << "Double Linked List의 크기 " << DoubleLinkedList.Size() << endl;
	// DoubleLinkedList.Show();
	// 
	// DoubleLinkedList.PushFront(99);
	// cout << "Double Linked List의 크기 " << DoubleLinkedList.Size() << endl;
	// DoubleLinkedList.Show();
	// 
	// DoubleLinkedList.PushBack(98);
	// cout << "Double Linked List의 크기 " << DoubleLinkedList.Size() << endl;
	// DoubleLinkedList.Show();
	// 
	// DoubleLinkedList.PushBack(97);
	// cout << "Double Linked List의 크기 " << DoubleLinkedList.Size() << endl;
	// DoubleLinkedList.Show();
	// 
	// DoubleLinkedList.PushBack(96);
	// cout << "Double Linked List의 크기 " << DoubleLinkedList.Size() << endl;
	// DoubleLinkedList.Show();
	// 
	// DoubleLinkedList.PopFront();
	// cout << "Double Linked List의 크기 " << DoubleLinkedList.Size() << endl;
	// DoubleLinkedList.Show();
	// 
	// cout << "---------------------------------------------------------------" << endl;
	// 
	// DoubleLinkedList.PopFront();
	// cout << "Double Linked List의 크기 " << DoubleLinkedList.Size() << endl;
	// DoubleLinkedList.Show();
	// 
	// DoubleLinkedList.PopFront();
	// cout << "Double Linked List의 크기 " << DoubleLinkedList.Size() << endl;
	// DoubleLinkedList.Show();
	// 
	// DoubleLinkedList.PopBack();
	// cout << "Double Linked List의 크기 " << DoubleLinkedList.Size() << endl;
	// DoubleLinkedList.Show();
	// 
	// DoubleLinkedList.PopBack();
	// cout << "Double Linked List의 크기 " << DoubleLinkedList.Size() << endl;
	// DoubleLinkedList.Show();

	DoubleLinkedList.Insert(1, 100);
	cout << "Double Linked List의 크기 " << DoubleLinkedList.Size() << endl;
	DoubleLinkedList.Show();

	DoubleLinkedList.Insert(2, 200);
	cout << "Double Linked List의 크기 " << DoubleLinkedList.Size() << endl;
	DoubleLinkedList.Show();

	DoubleLinkedList.Insert(3, 300);
	cout << "Double Linked List의 크기 " << DoubleLinkedList.Size() << endl;
	DoubleLinkedList.Show();




	DoubleLinkedList.~DoubleLinkedList();

	return 0;
}