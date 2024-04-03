#include <iostream>

using namespace std;

#define SIZE 10

template <typename T>
class AdjacencyList
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* link = NULL)
		{
			this->data = data;
			next = link;
		}
	};

	int size; // ������ ����
	T vertex[SIZE]; // ������ ����
	Node* list[SIZE]; // ���� ����Ʈ
public:

	AdjacencyList()
	{
		size = 0;

		for (int i = 0; i < SIZE; i++)
		{
			vertex[i] = NULL;
			list[i] = NULL;
		}
	}

	void Insert(T data)
	{
		if (size >= SIZE)
		{
			cout << "Adjacency List is Full" << endl;
			return;
		}

		vertex[size++] = data;
	}

	void Insert(int u, int v)
	{
		if (size <= 0)
		{
			cout << "Adjacency List is Empty" << endl;
			return;
		}

		if (u >= size || v >= size)
		{
			cout << "Out of Range" << endl;
			return;
		}

		list[u] = new Node(vertex[v], list[u]);
		list[v] = new Node(vertex[u], list[v]);
	}

	void Show()
	{
		if (size <= 0)
		{
			cout << "Adjacency List is Empty" << endl;
			return;
		}

		for (int i = 0; i < size; i++)
		{
			cout << vertex[i] << " : ";
			Node* current = list[i];
			while (current != nullptr)
			{
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}
	}


	~AdjacencyList()
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (list[i] != nullptr)
			{
				delete list[i];
			}
		}
	}

};

int main()
{
#pragma region ���� ����Ʈ(Adjacency List)
	// �׷����� �� ������ ������ �������� ���� ����Ʈ
	// �� ǥ���ϴ� ����Դϴ�.

	// ����
	// �׷����� ��� ������ ���� O(V+E)�� ǥ���� �� �ֽ��ϴ�.

	// ����
	// �� ������ �����ϴ� ������ ��ȸ�ϰų� ������ ������ �˱�
	// ���ؼ� ������ ���� ����Ʈ�� ��� Ž���ؾ� �ϹǷ�,
	// ������ ������ŭ�� �ð��� �ʿ��մϴ�.

	AdjacencyList<char> list;
	list.Insert('A');
	list.Insert('B');
	list.Insert('C');
	list.Insert('D');

	list.Insert(0, 1);
	list.Insert(0, 2);
	list.Insert(0, 3);
	list.Insert(2, 3);

	list.Show();



#pragma endregion



	return 0;
}