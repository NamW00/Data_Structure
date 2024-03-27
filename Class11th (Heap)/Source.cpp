#include <iostream>

#define SIZE 8

using namespace std;
// �� -> ��������Ʈ���� �����ȴ�.
// �ִ� ��(Max Heap) : ���� ū ���� ����⿡ �������� ���Ѵ�.
// key(�θ����� ��) > key(�ڽĳ���� ��) ������ �Ǿ��ִ�.
// ��������Ʈ���� ������ �ϸ鼭 ���԰� ������ �����ؾ��Ѵ�.
// �ִ� ���� ������ ������ Ʈ����.
// ������ �̷������ ������ ������ ���� �ִ��� ������ ó���� �ؾ��� -> �迭�� ���·� ó���ϰ� �ȴ�.
// ���� �ڽ��� �ε��� : (�θ����� �ε���) * 2
// ������ �ڽ��� �ε��� : (�θ����� �ε���) * 2 + 1
// �θ��� �ε��� : (�ڽĳ���� �ε���) / 2
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
		child = parent = index = 0;
	}

	// while ������ search �ϱ� ���� 
	// child = index
	// parent = index / 2 

	// �θ� ���� �ڽ� ��带 ���� ���� ����
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
			// �ڽ� ���� �θ� ����� �����͸� ���մϴ�.
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

	T& Delete()
	{
		// 1. ���� ����ִٰ� �Ѵٸ� ���α׷��� �����մϴ�.
		if (index < 1)
		{
			cout << "Heap Is Empty~!" << endl;
			exit(1);
		}

		// 2. �ӽ� ������ buffer[1]�� ���� �����մϴ�.
		T result = buffer[1];

		// 3. index�� ����Ű�� �迭�� ���� ù ��° ���ҿ� �־��ݴϴ�. 
		buffer[1] = buffer[index];

		// 4. index�� ����Ű�� �迭�� ���� �ʱ�ȭ�մϴ�.
		buffer[index] = NULL;

		// 5. index�� ���� ���ҽ�ŵ�ϴ�.
		index--;

		parent = 1;

		while (child <= index)
		{
			int child = parent * 2;

			// ������ �ڽ��� ��尡 Ŭ ��
			if (buffer[child] < buffer[child + 1])
			{
				child++;
			}

			if (buffer[child] < buffer[parent])
			{
				break;
			}

			swap(buffer[parent], buffer[child]);
			parent = child;
		}

		return result;
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

	for (int i = 0; i < SIZE; i++)
	{
		heap.Show();

		cout << "�ִ밪 : ";
		cout << heap.Delete() << endl;
	}

	return 0;
}


