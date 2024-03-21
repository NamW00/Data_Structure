#include <iostream>

using namespace std;
#define SIZE 4

#pragma region ���� ť
// ���������δ� ���� ������ ������ ������,
// ť�� �������� ������ ������ Queue�Դϴ�.

template <typename T>
class CircularQueue
{
private:
	T arr[SIZE] = { 0, };
	int front, rear;

public:
	CircularQueue()
	{
		front = rear = (SIZE - 1);
	}

	bool IsFull()
	{
		if (front == (rear + 1) % SIZE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Empty()
	{
		if (front == rear)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	T& Front()
	{
		if (Empty())
		{
			exit(1);
		}

		cout << "Front �� : " << arr[(front + 1) % SIZE] << endl;
	}

	void Push(T data)
	{
		if (IsFull())
		{
			cout << "Circular Queue Is Full~!" << endl;
		}
		else
		{
			arr[++rear % SIZE] = data;
		}

	}



	void Pop()
	{
		if (Empty())
		{
			cout << "Queue Is Empty~!" << endl;
		}
		else
		{
			front = (front + 1) % SIZE;
			arr[front] = NULL;

		}
	}

};

#pragma endregion

int main()
{
	CircularQueue<char> CircularQueue;
	CircularQueue.Push('A');
	CircularQueue.Front();

	CircularQueue.Push('B');
	CircularQueue.Front();

	CircularQueue.Push('C');
	CircularQueue.Front();

	CircularQueue.Push('D');
	CircularQueue.Front();

	CircularQueue.Push('E');
	CircularQueue.Front();

	return 0;
}