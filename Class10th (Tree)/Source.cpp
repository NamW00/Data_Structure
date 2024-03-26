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
	// 1. ���ο� ��带 �����մϴ�.
	Node* newNode = new Node;

	// 2. ���ο� ����� data���� �����մϴ�.
	newNode->data = data;

	// 3. ���ο� ����� left���� �����մϴ�.
	newNode->left = left;

	// 4. ���ο� ����� right���� �����մϴ�.
	newNode->right = right;

	// 5. ���ο� ����� �ּڰ��� ��ȯ�մϴ�.
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

	cout << "���� ��ȸ ��� : ";
	Preorder(node1);
	cout << endl;

	cout << "���� ��ȸ ��� : ";
	Inorder(node1);
	cout << endl;

	cout << "���� ��ȸ ��� : ";
	Postorder(node1);
	cout << endl;




	return 0;
}

// Tree(Ʈ��)
//		 (A)				-> level 0	/ height 3
//	   (B)��(C)				-> level 1	/ height 2
// (D)��(E) (F)��(G)			-> level 2	/ height 1
// root : A
// -> �ֻ��� ��带 �ǹ��մϴ�.
// edge : A-B
// -> ���� ��� ���̸� �����ϴ� ������ �ǹ��մϴ�.
// parent : A, B, C
// -> �ڽź��� ���� ��带 ������ �ִ� ��带 �ǹ��մϴ�.
// leaf : D, E, F, G
// -> �ڽ� ��带 ������ �ʴ� ��带 �ǹ��Ѵ�.
// level : root�� ���� �� ���� �ܰ踦 �����ϴ� ���Դϴ�.
// path : ���� ��� ���̰��� ��Ÿ���� ���� ������ ����
// degree : �ش� ��尡 �����ϴ� �ڽ� ����� ��
// �ð� ���⵵ : O(logN)�� ���⵵�� �ҿ�Ǿ� ���� �м� �ӵ��� �����ϴ�

// Ʈ�� ��ȸ
// ���� ��ȸ ( 1 -> 2 -> 4 -> 5 -> 3 -> 6 -> 7 )
// 1. Root Node�� �湮
// 2. ���� ���� Ʈ���� ���� ��ȸ�մϴ�.
// 3. ������ ���� Ʈ���� ���� ��ȸ�մϴ�.

// ���� ��ȸ ( 4 -> 2 -> 5 -> 1 -> 6 -> 3 -> 7 )
// 1. ���� ���� Ʈ���� ���� ��ȸ�մϴ�.
// 2. Root Node�� �湮
// 3. ������ ���� Ʈ���� ���� ��ȸ�մϴ�.

// ���� ��ȸ( 4 -> 5 -> 2 -> 6 -> 7 -> 3 -> 1 )
// 1. ���� ���� Ʈ���� ���� ��ȸ�մϴ�.
// 3. ������ ���� Ʈ���� ���� ��ȸ�մϴ�.
// 2. Root Node�� �湮


// ���� ���� Ʈ�� 
// ��� �� : n�� -> edge ���� : n - 1��
// ���� : h -> ��� �� : h ~ 2^h - 1��