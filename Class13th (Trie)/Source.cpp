#include <iostream>

using namespace std;

#define SIZE 26

class Trie
{
private:
	bool final;  // 기본적으로 불함수를 재정의 하지 않으면 false값으로 자동저장 된다.

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
		// 맨 마지막이 NULL('\0')을 향하게 되면 final = true 값을 반환해준다.
		if (*content == '\0')
		{
			final = true;
		}
		else
		{
			int index = *content - 'A';
			if (alphabet[index] == nullptr)
			{
				alphabet[index] = new Trie();
			}
			alphabet[index]->Insert(content + 1);
		}


	}

	bool Find(const char* content)
	{
		if (*content == '\0')
		{
			return true;
		}
		int index = *content - 'A';
		if (alphabet[index] == nullptr)
		{
			return false;
		}
		return alphabet[index]->Find(content + 1);

	}



	~Trie()
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (alphabet[i] == nullptr)
			{
				continue;
			}
		}
	}

};


int main()
{
	Trie trie;
	trie.Insert("KONE");
	trie.Insert("KOREA");
	trie.Insert("SOUND");
	trie.Insert("KILL");

	cout << trie.Find("KILL") << endl;
	cout << trie.Find("CHINA") << endl;
	cout << trie.Find("SOUND") << endl;
	cout << trie.Find("KANE") << endl;


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