﻿#include <iostream>
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

	// template 특수화 : 예외 처리
	// HashFunction template 특수화
	template <>
	int HashFunction(string key)
	{
		int result = 0;

		for (const char & element : key )
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

		// 생성한 노드의 주소값
		return newNode;
	}

	void Insert(KEY key, VALUE value)
	{
		// 1. 해쉬 함수를 통해서 값을 받는 임시 변수
		int tmp = HashFunction(key);
		// 2. 새로운 노드를 생성합니다.
		Node* newNode = CreateNode(key, value);

		if (bucket[tmp].count == 0)
		{
			// 1. bucket[tmp]의 head 포인터에 새로운 노드를 저장합니다.
			// -> 노드가 1개라도 존재하지 않는다면 헤드는 새로운 노드의 시작주소를 가리키고 있어야한다.
			bucket[tmp].head = newNode;

			// 2. bucket[tmp]의 count 변수의 값을 증가 시킵니다.
			bucket[tmp].count++;
		}
		else
		{
			// 1. newNode의 next에 bucket[tmp]의 head값을 저장합니다.
			newNode->next = bucket[tmp].head;

			// 2. bucket[tmp].head를 방금 새로 생성한 노드의 주소를 가리키게 합니다.
			bucket[tmp].head = newNode;

			// 3. bucket[tmp]의 count 변수의 값을 증가시킵니다.
			bucket[tmp].count++;
		}
	}

	// bucket[]은 정적할당을 했기 때문에 '->' 가 아니라 '.'으로 내부의 데이터로 접근을 해야한다.
	// Node와 같은 동적할당을 사용한 구조체일 경우에는 '->'
	void Show()
	{

		for (int i = 0; i < SIZE; i++)
		{
			Node* showNode = bucket[i].head;

			while (showNode != nullptr)
			{
				cout << "bucket[" << i << "]" << endl;
				cout << "Key 값 : " << showNode->key << endl;
				cout << "Value 값 : " << showNode->value << endl;
				showNode = showNode->next;
			}
			cout << endl;

		}
	}

	void Remove(KEY key)
	{
		int hashIndex = HashFunction(key);
		Node* deleteNode = bucket[hashIndex].head;
		Node* traceNode = deleteNode;

		
		if (deleteNode == nullptr)
		{
			cout << "bucket Is Empty~!" << endl;
		}
		else
		{
			// 2. 내가 삭제하고 싶은 key값과 head가 가리키는 key값을 비교한다.
			// -> deleteNode = deleteNode->next
			while (deleteNode->key != key)
			{
				traceNode = deleteNode;
				deleteNode = traceNode->next;
				traceNode->next = deleteNode;
			}

			
		}

		if (deleteNode == nullptr)
		{
			traceNode->next = nullptr;
			deleteNode = nullptr;
			delete deleteNode;
		}
		else
		{
			traceNode->next = deleteNode->next;
			deleteNode->next = nullptr;
			delete deleteNode;
		}
		
		
		

		
		
		// 3. 이전노드의 주소값을 저장할수 있는 node : traceNode
		// -> deleteNode 이전 노드를 가리키고 있어야한다.



	}
	
	
	// 동적 할당을 하므로 소멸자도 해주어야 한다.
	~HashTable()
	{

	}


};



int main()
{
#pragma region 해시 테이블
	// (Key, Value)로 데이터를 저장하는 자료 구조 중 하나로
	// 빠르게 데이터를 검색할 수 있는 자료 구조입니다.
	// 해시 충돌을 해결하는 방법
	// 1. 체이닝 기법
	// 각 해시 버킷을 연결 리스트로 구성하는 방식입니다.
	// 해시 충돌 발생 시 동일한 해시 값에 해당하는 데이터들을
	// 연결리스트로 연결하여 저장합니다.

	// 2. 개방 주소법
	// 충돌 발생 시 빈 버켓에 데이터를 저장하는 방식입니다.
	// 빈 버킷을 어떻게 결정할 지에 따라 구현 방식이 달라집니다.

	// 선형 탐사 : 충돌 발생 시 앞에서 부터 차례대로 빈 버킷을 
	// 찾아 저장하는 방식입니다.

	// 이차 탐사 : 충돌 발생 시 2^, 2^3 만큼 떨어진 빈 버킷을
	// 찾아 값을 저장하는 방식입니다.

	// 이중 해싱 : 해시 값을 한번 더 해시 함수에서 다른 함수를
	// 도출하는 방식입니다.


#pragma endregion
	HashTable<int, string> hashTable;

	hashTable.Insert(10, "Soccer");
	hashTable.Insert(27, "BaseBall");
	hashTable.Insert(14, "Tennis");
	hashTable.Insert(97, "BasketBall");
	hashTable.Insert(99, "Swimming");

	hashTable.Show();

	hashTable.Remove(99);
	hashTable.Show();


	return 0;
}