#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
	int size;
	int capacity;
	T* bufferptr;

public:
	Vector()
	{
		size = 0;
		capacity = 0;
		bufferptr = nullptr;
	}

	void PushBack(T data)
	{
		if (capacity == 0)
		{
			Resize(1);
		}
		else if (capacity <= size)
		{
			Resize(capacity * 2);
		}

		bufferptr[size++] = data;
	}

	void PopBack()
	{
		if (capacity <= 0)
		{
			cout << "Vector Is Empty~!" << endl;
		}
		else
		{
			bufferptr[--size] = 0;
		}

	}

	void Resize(int newSize)
	{
		// 1. Capacity�� ���ο� size���� �����մϴ�.
		capacity = newSize;

		// 2. ���ο� ������ ������ �����ؼ� ���Ӱ� ������� �޸� ������ ����Ű�� �մϴ�.
		// -> ���ο� �����Ͱ� ���� ���� �뷮�� 2��
		// T * bufferptr = new buffer[capacity];
		T* newptr = new T[capacity];

		// 3. ���ο� �޸� ������ ���� �ʱ�ȭ�մϴ�.
		for (int i = 0; i < capacity; i++)
		{
			newptr[i] = NULL;
		}

		// 4. ���� �迭�� �ִ� ���� �����ؼ� ���ο� �迭�� �־��ݴϴ�.
		for (int i = 0; i < size; i++)
		{
			newptr[i] = bufferptr[i];
		}

		// 5. bufferPointer�� ����Ű�� �޸� ������ �����մϴ�.
		if (bufferptr != nullptr)
		{
			// �迭[] ����� �����ָ� 0��° �ε����� �����ǰ� �������� �����ְ� �ȴ�. 
			// �� �޸� ������ �����.
			delete[] bufferptr;
		}


		// 6. bufferPointer�� ���ο� �޸� ������ �Ҵ��մϴ�.		
		bufferptr = newptr;
		newptr = nullptr;
	}

	// Reserve : Capacity�� �ش�ũ���� �޸𸮸� �����Ѵ�.
	// ����ó�� : newSize < capacity �϶��� ��ȯ�ؾ��Ѵ�.
	void Reserve(int newSize)
	{
		if (newSize < capacity)
		{
			return;
		}

		Resize(newSize);
	}

	// �����ε�
	// cout << vector[0]; ���� �ٷ� ȣ���� �� �ִ�. 
	// &�� ����Ͽ� index���� ���� ���簪�� ���� ������ �ʰ� ����Ʈ�� �ٷ� ������ �� �ִ�.
	T& operator [] (const int& index)
	{
		return bufferptr[index];
	}

	int& Size()
	{
		return size;
	}

	~Vector()
	{
		if (bufferptr != nullptr)
		{
			delete[] bufferptr;
		}
	}
};

int main()
{
	Vector<int> vector;
	vector.PushBack(10);
	vector.PushBack(20);
	vector.PushBack(30);

	for (int i = 0; i < vector.Size(); i++)
	{
		cout << vector[i] << " ";
	}
	cout << endl;


	return 0;
}