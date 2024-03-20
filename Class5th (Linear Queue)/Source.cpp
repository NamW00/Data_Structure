#include <iostream>

using namespace std;
#define SIZE 5

#pragma region ���� ť
// �迭�� ������ �� �����Ͱ� �����Ǿ�
// �����͸� �������� �ʱ�ȭ���� ������,
// ���� �����Ͱ� �ִ� �迭�� �ڸ��� �� �̻� �ٸ�����
// ���� �� ���� Queue�Դϴ�.

template <typename T> 
class LinearQueue
{
private:
	T arr[SIZE] = { 0, };
	int front, rear, size;

public:
	LinearQueue()
	{
		// for (int i = 0; i < SIZE; i++)
		// {
		// 	buffer[i] = NULL;
		// }

		front = rear = size = 0;
	}

	bool IsFull()
	{
		if (SIZE <= size)
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

	// ������� size���� Ư���� �κп� ���� ����Ǿ �� ���� return�Ǵµ�
	// reference�� �����ν� �������� �ٿ��ִ� ȿ���� ���� �� ����
	// reference  : ��ȯ�Ǵ� �� / size �� ���������ν� �� ��ü�� ��ȯ�� �� ����	
	int& Size()
	{
		return size;
	}

	// ���� ��ȯ�ϴ� �Լ����� ��쿣 &(���۷���)�� ������ ���°� ������ ������ ������ ������
	// �̸� ���ؼ� ������ �����ε��� ���ȴ�.


	T& Front()
	{
		if (Empty())
		{
			exit(1);
		}
		else
		{
			cout << "Front �� : " << endl;
			return arr[front];
		}
	}

	void Push(T data)
	{
		if (IsFull())
		{
			cout << "Queue Is Full~!" << endl;
			return;
		}

		arr[rear++] = data;

		size++;
	}



	void Pop()
	{
		if (Empty())
		{
			cout << "Queue Is Empty~!" << endl;
			return;
		}

		arr[front++] = NULL;

		size--;

	}

};

#pragma endregion

int main()
{
	LinearQueue<int> LinearQueue;

	LinearQueue.Empty();
	LinearQueue.IsFull();

	LinearQueue.Push(10);
	LinearQueue.Push(20);
	LinearQueue.Push(30);
	LinearQueue.Push(40);
	LinearQueue.Push(50);
	LinearQueue.Push(60);

	while (LinearQueue.Empty() == false)
	{
		cout << LinearQueue.Front() << endl;
		LinearQueue.Pop();

	}


	return 0;
}