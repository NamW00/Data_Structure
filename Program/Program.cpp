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

	// template 특수화 : 예외 처리
	// HashFunction template 특수화
	//	template <typename T>
	//	int HashFunction(T key)
	//	{
	//		int sum = 0;
	//		string hashIndex[SIZE];
	//		for (int i = 0; i <; i++)
	//		{
	//			
	//		}
	//		return hashIndex;
	//	}

	
	
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


	return 0;
}