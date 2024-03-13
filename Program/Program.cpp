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
		newNode->next = head;

		

		size++;

	}
	~SingleLinkedList()
	{
		
	}





};




	// PushFront(T data)
	// {
	// 
	// }
	// PushBack(T data)
	// {
	// 
	// }
	// head와 tail이 모두 nullptr이라고 하면 -> 


int main()
{
	SingleLinkedList  ;



	return 0;
}