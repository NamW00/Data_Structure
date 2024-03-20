#include <iostream>

using namespace std;
#define SIZE 5

#pragma region 선형 큐
// 배열의 공간에 들어간 데이터가 고정되어
// 데이터를 빼내더라도 초기화하지 않으며,
// 원래 데이터가 있던 배열의 자리에 더 이상 다른값이
// 들어올 수 없는 Queue입니다.

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

	// 원래라면 size값은 특정한 부분에 값이 복사되어서 그 값이 return되는데
	// reference를 씀으로써 복사비용을 줄여주는 효과를 얻을 수 있음
	// reference  : 반환되는 값 / size 로 정해줌으로써 값 자체를 반환할 수 있음	
	int& Size()
	{
		return size;
	}

	// 수를 반환하는 함수같은 경우엔 &(래퍼런스)를 무조건 쓰는게 복사비용 절감에 도움이 되지만
	// 이를 위해선 연산자 오버로딩이 사용된다.


	T& Front()
	{
		if (Empty())
		{
			exit(1);
		}
		else
		{
			cout << "Front 값 : " << endl;
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