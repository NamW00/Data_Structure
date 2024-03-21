#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
	int size;
	int capacity;
	T * bufferptr;

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
			Resize(capacity*2);
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
		// 1. Capacity에 새로운 size값을 설정합니다.
		capacity = newSize;

		// 2. 새로운 포인터 변수를 생성해서 새롭게 만들어진 메모리 공간을 가리키게 합니다.
		// -> 새로운 포인터가 힙에 기존 용량의 2배
		// T * bufferptr = new buffer[capacity];
		T * newptr = new T[capacity];
		
		// 3. 새로운 메모리 공간에 값을 초기화합니다.
		for (int i = 0; i < capacity; i++)
		{
			newptr[i] = NULL;
		}

		// 4. 기존 배열에 있는 값을 복사해서 새로운 배열에 넣어줍니다.
		for (int i = 0; i < size; i++)
		{
			newptr[i] = bufferptr[i];
		}

		// 5. bufferPointer가 가리키는 메모리 공간을 해제합니다.
		if (bufferptr != nullptr)
		{
			// 배열[] 모양을 안해주면 0번째 인덱스만 삭제되고 나머지는 남아있게 된다. 
			// 즉 메모리 누수가 생긴다.
			delete[] bufferptr;	
		}
		
		
		// 6. bufferPointer에 새로운 메모리 공간을 할당합니다.		
		bufferptr = newptr;
		newptr = nullptr;
	}

	// Reserve : Capacity에 해당크기의 메모리를 생성한다.
	// 예외처리 : newSize < capacity 일때는 반환해야한다.
	void Reserve(int newSize)
	{
		if (newSize < capacity)
		{
			return;
		}

		Resize(newSize);
	}

	// 오버로딩
	// cout << vector[0]; 으로 바로 호출할 수 있다. 
	// &를 사용하여 index값에 대한 복사값을 따로 만들지 않고 리스트에 바로 접근할 수 있다.
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