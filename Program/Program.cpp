#include <iostream>

using namespace std;

#define SIZE 26

template <typename T>
class Trie
{
private:
	bool final;

	Trie* alphabet[SIZE];	
public:
	Trie()
	{
		final = false;

		for (int i = 0; i < SIZE; i++)
		{
			alphabet[i] = nullptr;
		}
	}

	void Insert(const char* content)
	{
		// 맨 마지막이 NULL(\0)을 향하게 되면 final = true 값을 반환해준다.
		if (*content == '\0')
		{
			final = true;
			return;
		}
		else
		{
			int index = *content - 'A';
			if (alphabet[index] == nullptr)
			{
				alphabet[index] = new Trie();
				alphabet[index]->Insert(content + 1);
			}
		}
		

	}

	bool final()
	{

	}
	

	~Trie()
	{

	}

};


int main()
{


	return 0;
}
// A~Z
// 문자열의 길이(M) 만큼 시간복잡도O(n)만큼 형성된다.
// 문자열 "Kone", "Korea", Sound, Kill
//       (K)
//       / \
//     (O) (I)
//	   / \   \
//	 (N) (R) (L)
//   /     \   \
// (E)     (E) (L)
//           \
//           (A)