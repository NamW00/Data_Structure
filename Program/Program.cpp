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
		// top = SIZE - 1일 경우에도 Full인 상태이므로 해당된다.
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
			// top이 줄어들면 top위의 값들은 접근할 수 있는 방법이 없으므로
			// Push할때마다 그 값들을 새로 입력해주면 되기 때문에 크게 상관이 없음
			// 오히려 한문장으로 표현가능해서 연산속도가 차이나게 된다.
			return buffer[top--];
		}
		// buffer[top--] = NULL;
		// size--;
	}
	
	int &Size()
	{
		return size;
	}

	T & Top()
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
		else if(character == ')' || character == '}' || character == ']')
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

		

	// 열린 괄호(다 Push())와 닫힌 괄호(다 Pop())
	// {A [ (i+1) ] = 0;}
	// stack = { { , [ , ( };


	// 실패 조건 1 -> 열린 괄호의 top이 입력된 닫힌 괄호와 매칭 되지 않을 때
	// ( A + {B + 1] )

	// 실패 조건 2 -> stack에 데이터가 남아 있을 때
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
	// 	cout << "Stack의 Top : " << stack.Top() << endl;
	// 
	// 	stack.Pop();
	// }

	bool flag = CheckBraket("({[]})");
	cout << flag << endl;

	

	return 0;
}