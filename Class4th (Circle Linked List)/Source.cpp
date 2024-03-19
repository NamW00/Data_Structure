#include <iostream>

using namespace std;

template <typename T>
class CircularLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
	int position;
	int size;
	Node* head;
public:
	CircularLinkedList()
	{
		position = 0;
		size = 0;
		head = nullptr;
	}

	void PushFront(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;

			newNode->next = head;
		}
		else
		{
			// 1. newNode�� next�� head�� next�� ����Ŵ
			newNode->next = head->next;
			// 2. head�� Next�� newnode�� ����Ŵ
			head->next = newNode;

		}
		size++;

	}

	void PushBack(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;

			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;

			head->next = newNode;

			head = newNode;
		}
		size++;

	}

	void PopFront()
	{

		if (size == 0)
		{
			cout << "List is Empty~!" << endl;
			return;
		}

		Node* deleteNode = head->next;

		if (size == 1)
		{
			deleteNode = head;

			delete deleteNode;

			head = nullptr;
		}
		else
		{
			deleteNode = head->next;

			head->next = deleteNode->next;

			delete deleteNode;
		}

		size--;
	}

	void PopBack()
	{

		if (size == 0)
		{
			cout << "List is Empty~!" << endl;
			return;
		}

		// 1. currentNode�� deleteNode�� head�� ����Ų��.
		Node* currentNode = head;
		Node* deleteNode = head;


		if (size == 1)
		{
			delete deleteNode;

			head = nullptr;
		}
		else
		{
			// 2. currentNode�� size - 1��ŭ �̵� ��Ų��.
			for (int i = 0; i < size - 1; i++)
			{
				currentNode = currentNode->next;
			}

			// 3. currentNode�� next�� head�� ���� ��ġ�� ����Ų��.
			currentNode->next = head->next;

			// 4. head�� ��ġ�� �ű��.
			head = currentNode;

			// 5. deleteNode�� �����Ѵ�.
			delete deleteNode;
		}

		size--;
	}
	void Show()
	{
		Node* searchNode = head;
		if (size == 0)
		{
			return;
		}
		else
		{
			cout << "Show List : ";
			for (int i = 0; i < size; i++)
			{
				cout << searchNode->data << " ";
				searchNode = searchNode->next;
			}

			cout << endl;
		}
	}
	// void Insert(int position, T data)
	// {
	// 	Node* insertNode = head;
	// 	insertNode->data = data;
	// 	if (size == 0)
	// 	{
	// 		return;
	// 	}
	// 	else
	// 	{
	// 		
	// 		for (int i = 0; i < position; i++)
	// 		{
	// 			insertNode = insertNode->next;
	// 		}
	// 
	// 
	// 		cout << endl;
	// 	}
	// }

	~CircularLinkedList()
	{
		while (size != 0)
		{
			PopFront();
		}
	}



};

int main()
{
	CircularLinkedList<int> CircularLinkedList;

	CircularLinkedList.PushFront(10);
	CircularLinkedList.PushBack(20);
	CircularLinkedList.PushBack(30);
	CircularLinkedList.PushFront(40);
	CircularLinkedList.Show();

	CircularLinkedList.PopBack();
	CircularLinkedList.Show();

	CircularLinkedList.PopFront();
	CircularLinkedList.Show();

	CircularLinkedList.PopFront();
	CircularLinkedList.Show();

	CircularLinkedList.PopBack();
	CircularLinkedList.Show();

	CircularLinkedList.PopBack();



	return 0;
}