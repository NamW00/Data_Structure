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

	int size;
	Node* head;
public:
	CircularLinkedList()
	{
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
			// 1. newNode의 next는 head의 next를 가리킴
			newNode->next = head->next;
			// 2. head의 Next는 newnode를 가리킴
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

		// 1. currentNode와 deleteNode는 head를 가리킨다.
		Node * currentNode = head;
		Node * deleteNode = head;

		
		if (size == 1)
		{
			delete deleteNode;

			head = nullptr;
		}
		else
		{
			// 2. currentNode를 size - 1만큼 이동 시킨다.
			for (int i = 0; i < size - 1; i++)
			{
				currentNode = currentNode->next;
			}

			// 3. currentNode의 next는 head의 다음 위치를 가리킨다.
			currentNode->next = head->next;

			// 4. head의 위치를 옮긴다.
			head = currentNode;

			// 5. deleteNode를 삭제한다.
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
			for (int i = 0; i < size; i++)
			{
				cout << searchNode->data << " ";
				searchNode = searchNode->next;
			}

			cout << endl;
		}
	}
		
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


	
	return 0;
}