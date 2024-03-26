#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

int countnode = 0;
int countleafnode = 0;

Node* createNode(int data, Node* left, Node* right)
{
	// 1. 새로운 노드를 생성합니다.
	Node* newNode = new Node;

	// 2. 새로운 노드이 data값을 저장합니다.
	newNode->data = data;

	// 3. 새로운 노드의 left값을 저장합니다.
	newNode->left = left;

	// 4. 새로운 노드의 right값을 저장합니다.
	newNode->right = right;

	// 5. 새로운 노드의 주솟값을 반환합니다.
	return newNode;
}

void Preorder(Node* root)
{
	if (root != nullptr)
	{
		cout << root->data << " ";
		Preorder(root->left);
		Preorder(root->right);
	}
}

void Inorder(Node* root)
{
	if (root != nullptr)
	{
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
}

void Postorder(Node* root)
{
	if (root != nullptr)
	{
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data << " ";
	}
}

//	Node* countNode(Node * node)
//	{
//		
//		if (node == nullptr)
//		{
//			cout << "Tree Is Empty~!" << endl;
//			return countnode;
//		}
//		else
//		{
//			return 1 + countNode(node->left) + countNode(node->right);
//	
//		}
//	}
//	
//	Node* countLeaf(Node* node)
//	{
//		if (node == nullptr)
//		{
//			cout << "Tree Is Empty~!" << endl;
//			return;
//		}
//		else if (node->left == nullptr && node->right == nullptr)
//		{
//			cout << "Tree has Root Node~!" << endl;
//			return;
//		}
//		else
//		{
//			return countLeaf(node->left) + countLeaf(node->right);
//		}
//	}

int main()
{
	Node* node7 = createNode(7, nullptr, nullptr);
	Node* node6 = createNode(6, nullptr, nullptr);
	Node* node5 = createNode(5, nullptr, nullptr);
	Node* node4 = createNode(4, nullptr, nullptr);
	Node* node3 = createNode(3, node6, node7);
	Node* node2 = createNode(2, node4, node5);
	Node* node1 = createNode(1, node2, node3);

	cout << "전위 순회 결과 : ";
	Preorder(node1);
	cout << endl;

	cout << "중위 순회 결과 : ";
	Inorder(node1);
	cout << endl;

	cout << "후위 순회 결과 : ";
	Postorder(node1);
	cout << endl;




	return 0;
}

// Tree(트리)
//		 (A)				-> level 0	/ height 3
//	   (B)ㅗ(C)				-> level 1	/ height 2
// (D)ㅗ(E) (F)ㅗ(G)			-> level 2	/ height 1
// root : A
// -> 최상위 노드를 의미합니다.
// edge : A-B
// -> 노드와 노드 사이를 연결하는 간선을 의미합니다.
// parent : A, B, C
// -> 자신보다 하위 노드를 가지고 있는 노드를 의미합니다.
// leaf : D, E, F, G
// -> 자식 노드를 가지지 않는 노드를 의미한다.
// level : root로 부터 그 하위 단계를 측정하는 것입니다.
// path : 노드와 노드 사이간에 나타나는 노드와 간선의 순서
// degree : 해당 노드가 포함하는 자식 노드의 수
// 시간 복잡도 : O(logN)의 복잡도가 소요되어 파일 분석 속도에 유리하다

// 트리 순회
// 전위 순회 ( 1 -> 2 -> 4 -> 5 -> 3 -> 6 -> 7 )
// 1. Root Node를 방문
// 2. 왼쪽 서브 트리를 전위 순회합니다.
// 3. 오른쪽 서브 트리를 전위 순회합니다.

// 중위 순회 ( 4 -> 2 -> 5 -> 1 -> 6 -> 3 -> 7 )
// 1. 왼쪽 서브 트리를 중위 순회합니다.
// 2. Root Node를 방문
// 3. 오른쪽 서브 트리를 중위 순회합니다.

// 후위 순회( 4 -> 5 -> 2 -> 6 -> 7 -> 3 -> 1 )
// 1. 왼쪽 서브 트리를 후위 순회합니다.
// 3. 오른쪽 서브 트리를 후위 순회합니다.
// 2. Root Node를 방문


// 완전 이진 트리 
// 노드 수 : n개 -> edge 개수 : n - 1개
// 높이 : h -> 노드 수 : h ~ 2^h - 1개