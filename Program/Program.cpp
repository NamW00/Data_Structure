#include <iostream>

#define SIZE 8

using namespace std;

template <typename T>
class Heap
{
private:
	T buffer[SIZE];
	int index;
	int child;
	int parent;

public:
	Heap()
	{
		for (int i = 0; i < SIZE; i++)
		{
			buffer[i] = NULL;
		}

		index = 0;
	}

	// while 문으로 search 하기 전에 
	// child = index
	// parent = index / 2 

	// 부모 노드와 자식 노드를 서로 비교할 떄는
	// child <- parent;
	// parent <- child / 2;

	void Insert(T data)
	{
		if (index >= SIZE - 1)
		{
			cout << "Heap Is Full~!" << endl;
			return;
		}

		buffer[++index] = data;

		child = index;
		parent = index / 2;

		while (child != 1) // && buffer[child] > buffer[parent]
		{
			// 자식 노드와 부모 노드의 데이터를 비교합니다.
			if (buffer[parent] < buffer[child])
			{
				swap(buffer[parent], buffer[child]);
			}
			child = parent;
			parent = child / 2;
			// buffer[index] = data;
			// child = index;
			// parent = index / 2;
			// while (child != 1 && buffer[child] > buffer[parent])
			// {
			// 	swap(buffer[child], buffer[parent])
			// 		child /= 2;
			// 	parent /= 2;
			// }
		}
	}

	T & Delete()
	{
		
		
		// 1. 힙이 비어있다고 한다면 프로그램을 종료합니다.
		if (index <= 1)
		{
			cout << "Heap Is Empty~!" << endl;
			exit(1);
		}
		
		// 2. 임시 변수에 buffer[1]의 값을 보관합니다.
		T result = buffer[1];

		// 3. index로 가리키는 배열의 값을 첫 번째 원소에 넣어줍니다. 
		buffer[1] = buffer[index];
		
		// 4. index로 가리키는 배열의 값을 초기화합니다.
		buffer[index] = NULL;
		
		// 5. index의 값을 감소시킵니다.
		index--;

		parent = 1;
		child = 2;

		while (child <= index)
		{
			if (buffer[child] < buffer[child + 1])
			{
				child += 1;
			}
			
			if (buffer[parent] < buffer[child])
			{
				swap(buffer[parent], buffer[child]);
			}

			parent = child;
			child = parent * 2;
		}
	}

	void Show()
	{
		for (T element : buffer)
		{
			cout << element << " ";
		}
		cout << endl;
	}

};

int main()
{
	Heap<int> heap;
	heap.Insert(1);
	heap.Insert(2);
	heap.Insert(3);
	heap.Insert(4);
	heap.Insert(5);
	heap.Insert(6);
	heap.Insert(7);
	heap.Show();


	for (int i = 0; i < SIZE; i++)
	{
		heap.Delete();
		heap.Show();
	}

	return 0;
}

// 힙 -> 완전이진트리로 구성된다.
//				(10)
//			(6)		 (7)
//
//

// 최대 힙(Max Heap) : 가장 큰 값이 꼭대기에 있을때를 말한다.
// key(부모노드의 값) > key(자식노드의 값) 구조로 되어있다.
// 완전이진트리를 유지를 하면서 삽입과 삭제를 진행해야한다.
// 최대 값을 뽑을때 유리한 트리다.
// 힙에서 이루어지기 때문에 데이터 값을 최대한 빠르게 처리를 해야한다. -> 배열의 형태로 처리하게 된다.
// 왼쪽 자식의 인덱스 : (부모노드의 인덱스) * 2
// 오른쪽 자식의 인덱스 : (부모노드의 인덱스) * 2 + 1
// 부모의 인덱스 : (자식노드의 인덱스) / 2
