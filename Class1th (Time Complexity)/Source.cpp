#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;

	~Node() // struct도 소멸자 따로 생성 가능하다.
	{
		cout << "delete Node~!" << endl;
	}
};

struct HeadNode
{
	Node* head;
};

void PushFront(Node* target, int data)
{
	Node* newNode = new Node;

	newNode->data = data;

	newNode->next = target->next;

	target->next = newNode;
}


int main()
{
#pragma region 시간복잡도
	// 컴퓨터 프로그램의 입력 값과 연산 수행 시간의
	// 상관관계를 나타내는 척도입니다.

	// Big-O 표기법
	// 인수가 특정 값이나 무한대로 향하는 경향이
	// 있을 때 함수의 제한 동작을 설명하는 수학적 표기법

	// O(1) constant Complexity
	// 입력 값이 증가하더라도 시간이 늘어나지 않는 
	// 시간 복잡도입니다.

	// ex) 배열의 원소 접근, 벡터, 스텍, 큐

	// O(n) linear complexity
	// 입력 값이 증가함에 따라 시간 또한 같은 비율로
	// 증가하는 시간 복잡도입니다.

	// ex) for문 반복문

	// O(log n) logarithmic time
	// 입력 값이 커질 때 연산 횟수가 logN에 비례해서
	// 증가하는 시간 복잡도 입니다.

	// ex) 이진 검색 트리(BST)

	// O(n^2) Quadratic Complexity
	// 입력 값이 증가함에 따라 시간이 n의 제곱수의
	// 비율로 증가하는 시간 복잡도

	// ex) 이중 for문

#pragma endregion

#pragma region 연결 리스트
	// Node* head = new Node; // head가 동적할당(new Node)한 dummy Node를 가리키고 있음 
	// head->data = 0;
	// head->next = nullptr; // 더미 노드가 nullptr을 가리키도록
	// 
	// PushFront(head, 100);
	// PushFront(head, 99);
	// PushFront(head, 98);
	// 
	// 
	// Node* currentNode = head->next;
	// while (currentNode != NULL)
	// {
	// 	cout << currentNode->data << endl;
	// 	currentNode = currentNode->next;
	// }
	// 
	// 
	// currentNode = head; // head도 new Node로 선언했기 때문에 더미값이 
	// 
	// 
	// while (currentNode != NULL)
	// {
	// 	// 1. head의 주소를 currentNode->next로 넣어줍니다.
	// 	head = currentNode->next;
	// 
	// 	// 2. currentNode가 가리키는 노드 삭제
	// 	delete currentNode;
	// 
	// 	// 3. currentNode에 head의 주솟값을 넣어줍니다.
	// 	currentNode = head;
	// }

	// // Node 1, Node 2 를 생성하고 각각의 노드에 10, 20을 넣어줌
	// Node *node1 = new Node;
	// 
	// head->next = node1;
	// node1->data = 10;
	// 
	// Node *node2 = new Node;
	// 
	// node1->next = node2;
	// node2->data = 20;
	// 
	// node2->next = nullptr;

#pragma endregion

	return 0;
}
