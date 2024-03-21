#include <iostream>

using namespace std;
#define SIZE 4

#pragma region 원형 큐
// 물리적으로는 선형 구조를 가지고 있으며,
// 큐의 시작점과 끝점을 연결한 Queue입니다.

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

		cout << "Front 값 : " << arr[(front + 1) % SIZE] << endl;
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