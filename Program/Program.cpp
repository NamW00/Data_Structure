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


	bool Find(T data)
	{
		Node* currentNode = root;
		if (currentNode->data == NULL)
		{
			return false;
		}

		while (currentNode != nullptr)
		{
			if (currentNode->data == data)
			{
				return true;
			}
			else if (currentNode->data < data)
			{
				currentNode = currentNode->right;
			}
			else
			{
				currentNode = currentNode->left;
			}
		}
		return false;
	}

	Node * FindNode(T data)
	{
		Node* currentNode = root;
		if (currentNode->data == NULL)
		{
			cout << "data is not found" << endl;
			return;
		}

		while (currentNode != nullptr)
		{
			if (currentNode->data == data)
			{
				return currentNode;
			}
			else if (currentNode->data < data)
			{
				currentNode = currentNode->right;
			}
			else
			{
				currentNode = currentNode->left;
			}
		}
		cout << "data is not found" << endl;
		return;
	}

	void Remove(T data)
	{	
		Node* currentNode = root;
		Node* parentNode = nullptr;
		
		// root가 nullptr일때
		if (currentNode == nullptr)
		{
			cout << "BST Is Empty~!" << endl;
			return;
		}

		// currentNode로 삭제할 값을 탐색
		while (currentNode->data != data)
		{
			if (currentNode->data > data)
			{
				parentNode = currentNode;
				currentNode = currentNode->left;
			}
			else if (currentNode->data < data)
			{
				parentNode = currentNode;
				currentNode = currentNode->right;
			}
			
		}
		// 끝까지 탐색한 후에도 결과값을 찾지 못했을때
		if (currentNode == nullptr)
		{
			cout << "Data not found in the tree." << endl;
			return;
		}

		// Case 1 : 삭제하려는 노드가 리프노드인 경우
		if (currentNode->left == nullptr && currentNode->right == nullptr)
		{
			if (parentNode != nullptr)
			{
				if (parentNode->left == currentNode)
				{
					parentNode->left = nullptr;
				}				
				else
				{
					parentNode->right = nullptr;
				}
			}
		}
		// Case 2 : 자식 노드가 한개만 있는 경우
		else if (currentNode->left == nullptr || currentNode->right == nullptr)
		{
			Node* childNode = nullptr;
			if (currentNode->left != nullptr) // 왼쪽에만 자식이 있을때
			{
				childNode = currentNode->left;
			}
			else // 오른쪽에만 자식이 있을때
			{
				childNode = currentNode->right;
			}

			if (parentNode != nullptr)
			{
				if (parentNode->left == currentNode) 
				{
					parentNode->left = childNode;
				}
				else
				{
					parentNode->right = childNode;
				}
			}
		}
		else // 자식이 두개다 있을 때 
		{
			// 오른쪽 자식노드의 가장 왼쪽에 있는 값을 들고와야 완전 이진 트리를 유지하면서
			Node* childNode = currentNode->right;
			Node* traceNode = currentNode;

			while (childNode->left != nullptr)
			{
				traceNode = childNode;
				childNode = childNode->left;
			}

			if (traceNode->left == traceNode)
			{
				traceNode->left = childNode->right;
			}
			else
			{
				traceNode->right = childNode->right;
			}
			currentNode->data = childNode->data;
			delete childNode;
		}
		delete currentNode;
	}

	void Trace(Node*currentNode)
	{
		if (currentNode != nullptr)
		{
			Trace(currentNode->right);
			cout << currentNode->data << " ";
			Trace(currentNode->left);
		}
	}

	void Show()
	{
		Node* currentNode = root;
		Trace(currentNode);
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
	BinarySearchTree<int> BST;
	BST.Insert(8);
	BST.Insert(5);
	BST.Insert(10);
	BST.Insert(34);
	BST.Insert(1);
	BST.Insert(9);

	BST.Show();


#pragma endregion

	return 0;
}