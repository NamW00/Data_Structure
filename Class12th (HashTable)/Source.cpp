#include <iostream>
#include <string>
using namespace std;

#define SIZE 6

template <typename KEY, typename VALUE>
class HashTable
{
private:
	struct Node
	{
		KEY key;
		VALUE value;
		Node* next;
	};

	struct Bucket
	{
		int count;
		Node* head;
	};

	Bucket bucket[SIZE];

public:
	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i].count = 0;
			bucket[i].head = nullptr;
		}

	}

	template <typename T>
	int HashFunction(T key)
	{
		int hashIndex = (int)key % SIZE;
		return hashIndex;
	}

	// template Ư��ȭ : ���� ó��
	// HashFunction template Ư��ȭ
	template <>
	int HashFunction(string key)
	{
		int result = 0;

		for (const char& element : key)
		{
			result += (int)element;
		}

		//	for (int i = 0; i < key.length(); i++)
		//	{
		//		result += (int)key[i];
		//	}

		int hashIndex = result % SIZE;

		return hashIndex;
	}

	Node* CreateNode(KEY key, VALUE value)
	{
		Node* newNode = new Node;

		newNode->key = key;

		newNode->value = value;

		newNode->next = nullptr;

		// ������ ����� �ּҰ�
		return newNode;
	}

	void Insert(KEY key, VALUE value)
	{
		// 1. �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽ� ����
		int tmp = HashFunction(key);
		// 2. ���ο� ��带 �����մϴ�.
		Node* newNode = CreateNode(key, value);

		if (bucket[tmp].count == 0)
		{
			// 1. bucket[tmp]�� head �����Ϳ� ���ο� ��带 �����մϴ�.
			// -> ��尡 1���� �������� �ʴ´ٸ� ���� ���ο� ����� �����ּҸ� ����Ű�� �־���Ѵ�.
			bucket[tmp].head = newNode;

			// 2. bucket[tmp]�� count ������ ���� ���� ��ŵ�ϴ�.
			bucket[tmp].count++;
		}
		else
		{
			// 1. newNode�� next�� bucket[tmp]�� head���� �����մϴ�.
			newNode->next = bucket[tmp].head;

			// 2. bucket[tmp].head�� ��� ���� ������ ����� �ּҸ� ����Ű�� �մϴ�.
			bucket[tmp].head = newNode;

			// 3. bucket[tmp]�� count ������ ���� ������ŵ�ϴ�.
			bucket[tmp].count++;
		}
	}

	// bucket[]�� �����Ҵ��� �߱� ������ '->' �� �ƴ϶� '.'���� ������ �����ͷ� ������ �ؾ��Ѵ�.
	// Node�� ���� �����Ҵ��� ����� ����ü�� ��쿡�� '->'
	void Show()
	{

		for (int i = 0; i < SIZE; i++)
		{
			Node* showNode = bucket[i].head;

			while (showNode != nullptr)
			{
				cout << "bucket[" << i << "] -> Key �� : " << showNode->key << "/ Value �� : " << showNode->value << endl;
				showNode = showNode->next;
			}
			cout << endl;

		}
	}

	void Remove(KEY key)
	{
		// 1. �ؽ� �Լ��� ���ؼ� ���� �޴� �ӽ� ����
		int hashIndex = HashFunction(key);

		// 2. Node�� Ž���� �� �ִ� ��ȸ�� ������ ���� ����
		Node* deleteNode = bucket[hashIndex].head;

		// 3. ���� ��带 ������ �� �ִ� ������ ���� ����
		Node* traceNode = nullptr;

		// 4. deleteNode�� nullptr�̶�� �ϸ� �Լ��� �����մϴ�.
		if (deleteNode == nullptr)
		{
			cout << "Not Key Found~!" << endl;
			return;
		}

		// 5. deleteNode�� �̿��ؼ� ���� ã���� �ϴ� key ���� ã���ϴ�.
		while (deleteNode != nullptr)
		{
			// deleteNode->key ���� ���� �����ϰ� ���� key���� ���ٸ�
			if (deleteNode->key == key)
			{
				// ���� �����ϰ��� �ϴ� key�� head�� �ִ� �����
				if (deleteNode == bucket[hashIndex].head)
				{
					bucket[hashIndex].head = deleteNode->next;
				}
				else
				{
					traceNode->next = deleteNode->next;
				}

				// �� bucket�� ī��Ʈ ���� ���ҽ�ŵ�ϴ�.
				bucket[hashIndex].count--;

				// �ش� �޸𸮸� �����մϴ�.
				delete deleteNode;

				return;
			}
			traceNode = deleteNode;
			deleteNode = deleteNode->next;
		}

		cout << "Not Key Found~!" << endl;

	}



	// ���� �Ҵ��� �ϹǷ� �Ҹ��ڵ� ���־�� �Ѵ�.
	~HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			Node* deleteNode = bucket[i].head;
			Node* nextNode = deleteNode;

			if (deleteNode == nullptr)
			{
				continue;
			}
			else
			{
				while (nextNode != nullptr)
				{
					nextNode = deleteNode->next;

					delete deleteNode;

					deleteNode = nextNode;
				}
			}


		}
	}


};



int main()
{
#pragma region �ؽ� ���̺�
	// (Key, Value)�� �����͸� �����ϴ� �ڷ� ���� �� �ϳ���
	// ������ �����͸� �˻��� �� �ִ� �ڷ� �����Դϴ�.
	// �ؽ� �浹�� �ذ��ϴ� ���
	// 1. ü�̴� ���
	// �� �ؽ� ��Ŷ�� ���� ����Ʈ�� �����ϴ� ����Դϴ�.
	// �ؽ� �浹 �߻� �� ������ �ؽ� ���� �ش��ϴ� �����͵���
	// ���Ḯ��Ʈ�� �����Ͽ� �����մϴ�.

	// 2. ���� �ּҹ�
	// �浹 �߻� �� �� ���Ͽ� �����͸� �����ϴ� ����Դϴ�.
	// �� ��Ŷ�� ��� ������ ���� ���� ���� ����� �޶����ϴ�.

	// ���� Ž�� : �浹 �߻� �� �տ��� ���� ���ʴ�� �� ��Ŷ�� 
	// ã�� �����ϴ� ����Դϴ�.

	// ���� Ž�� : �浹 �߻� �� 2^, 2^3 ��ŭ ������ �� ��Ŷ��
	// ã�� ���� �����ϴ� ����Դϴ�.

	// ���� �ؽ� : �ؽ� ���� �ѹ� �� �ؽ� �Լ����� �ٸ� �Լ���
	// �����ϴ� ����Դϴ�.


#pragma endregion
	HashTable<int, string> hashTable;

	hashTable.Insert(10, "Soccer");
	hashTable.Insert(27, "BaseBall");
	hashTable.Insert(14, "Tennis");
	hashTable.Insert(97, "BasketBall");
	hashTable.Insert(85, "Swimming");

	hashTable.Show();

	hashTable.Remove(85);
	hashTable.Remove(10);
	hashTable.Remove(14);
	hashTable.Show();
	cout << "=============================================" << endl;
	return 0;
}