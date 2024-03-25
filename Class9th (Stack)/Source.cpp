#include <iostream>
#include <string>
#define SIZE 10

using namespace std;


template <typename T>
class Stack
{
private:
	int top;
	int size;
	T buffer[SIZE] = { 0, };

public:
	Stack()
	{
		size = 0;
		top = -1;
	}

	bool Empty()
	{
		if (top <= -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool IsFull()
	{
		// top = SIZE - 1�� ��쿡�� Full�� �����̹Ƿ� �ش�ȴ�.
		if (SIZE - 1 <= top)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Push(T data)
	{
		if (IsFull())
		{
			cout << "Stack Is Full~!" << endl;
		}
		else
		{
			buffer[++top] = data;
			size++;
		}

	}

	T Pop()
	{
		if (Empty())
		{
			cout << "Stack Is Empty~!" << endl;
		}
		else
		{
			// top�� �پ��� top���� ������ ������ �� �ִ� ����� �����Ƿ�
			// Push�Ҷ����� �� ������ ���� �Է����ָ� �Ǳ� ������ ũ�� ����� ����
			// ������ �ѹ������� ǥ�������ν� ����ӵ����� ���̰� �ִ�.
			return buffer[top--];
		}
		// buffer[top--] = NULL;
		// size--;
	}

	int& Size()
	{
		return size;
	}

	T& Top()
	{
		return buffer[top];
	}

};

bool CheckBraket(string content)
{
	Stack<char> stack;

	for (int i = 0; i < content.length(); i++)
	{
		char character = content[i];

		if (character == '(' || character == '{' || character == '[')
		{
			stack.Push(character);
		}
		else if (character == ')' || character == '}' || character == ']')
		{
			char alphabet = stack.Pop();

			if (alphabet == '(' && character != ')')
			{
				return false;
			}

			if (alphabet == '{' && character != '}')
			{
				return false;
			}

			if (alphabet == '[' && character != ']')
			{
				return false;
			}
		}
	}
	if (stack.Empty())
	{
		return true;
	}
	else
	{
		return false;
	}



	// if (content.length() % 2 == 1)
	// {
	// 	return false;
	// }
	// else
	// {
	// 	for (int i = 0; i < content.length()/2; i++)
	// 	{
	// 		char character = content[i];
	// 
	// 		switch (character)
	// 		{
	// 		case '(':
	// 			stack.Push('(');
	// 			break;
	// 		case '{':
	// 			stack.Push('{');
	// 			break;
	// 		case '[':
	// 			stack.Push('[');
	// 			break;
	// 		default:
	// 			return false;
	// 			break;
	// 		}
	// 	}
	// 	for (int i = content.length()/2; i < content.length(); i++)
	// 	{
	// 		char character = content[i];
	// 
	// 		
	// 	}
	// }



	// ���� ��ȣ(�� Push())�� ���� ��ȣ(�� Pop())
	// {A [ (i+1) ] = 0;}
	// stack = { { , [ , ( };


	// ���� ���� 1 -> ���� ��ȣ�� top�� �Էµ� ���� ��ȣ�� ��Ī ���� ���� ��
	// ( A + {B + 1] )

	// ���� ���� 2 -> stack�� �����Ͱ� ���� ���� ��
	// (A + B {C + 0} 


}

int main()
{
	Stack<char> stack;

	// stack.Push(10);
	// stack.Push(20);
	// stack.Push(30);
	// stack.Push(40);
	// stack.Push(50);
	// stack.Push(60);
	// 
	// while (stack.Empty() == false)
	// {
	// 	cout << "Stack�� Top : " << stack.Top() << endl;
	// 
	// 	stack.Pop();
	// }

	bool flag = CheckBraket("({[]})");
	if (flag)
	{
		cout << "��ȣ�˻� ��� : ���������� �Ǻ��Ǿ����ϴ�~!" << endl;
	}
	else
	{
		cout << "��ȣ�˻� ��� : ������������ �Ǻ��Ǿ����ϴ�. �ٽ� Ȯ���� �ֽʽÿ�~!" << endl;
	}



	return 0;
}