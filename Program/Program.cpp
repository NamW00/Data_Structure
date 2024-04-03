#include <iostream>

using namespace std;

template <typename T>
class BinarySearchTree
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};

	Node* root;
public:
	BinarySearchTree()
	{
		root = nullptr;
	}


	Node* CreateNode(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->left = nullptr;
		newNode->right = nullptr;

		return newNode;
	}

	void Insert(T data)
	{
		

		if (root == nullptr)
		{
			root = CreateNode(data);
			return;
		}
		else
		{
			Node* currentNode = root;
			while (currentNode != nullptr)
			{
				if (currentNode->data == data) // 내가 삽입하고자 하는 값이 root값과 같다면
				{
					return;
				}
				else if (currentNode->data < data) // 내가 삽입하고자 하는 값이 root값 보다 작다면
				{
					if (currentNode->left == nullptr)
					{
						currentNode->left = CreateNode(data);
						break;
					}
					else
					{
						currentNode = currentNode->left;
					}
				}
				else // 내가 삽입하고자 하는 값이 root값 보다 크다면
				{
					if (currentNode->right == nullptr)
					{
						currentNode->right = CreateNode(data);
						break;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}
				
			}
		}
	}

	void Find(T data)
	{
		Node* currentNode = CreateNode(data);

	}

	void delete(T data)
	{
		Node * deleteNode = CreateNode(data);

	}


	~BinarySearchTree()
	{

	}

};


int main()
{
#pragma region 이진 탐색 트리
	// 한 노드에 대해 왼쪽/오른쪽의 (최대) 두개의 자식을 가질수있는 트리이며,
	// 왼쪽자식은 부모 노드보다 작은 값을, 오른쪽자식은 부모 노드보다 큰값을
	// 가지는 탐색트리입니다.
	// 완전 이진 트리일 필요는 없고 


#pragma endregion

	return 0;
}