#include <iostream>

using namespace std;

#define SIZE 26

class Trie
{
private:
	bool final;  // �⺻������ ���Լ��� ������ ���� ������ false������ �ڵ����� �ȴ�.

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
		// �� �������� NULL('\0')�� ���ϰ� �Ǹ� final = true ���� ��ȯ���ش�.
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
// ���ڿ��� ����(M) ��ŭ �ð����⵵O(n)��ŭ �����ȴ�.
// ���ڿ� "Kone", "Korea", Sound, Kill
//       (K)
//       / \
//     (O) (I)
//	   / \   \
//	 (N) (R) (L)
//   /     \   \
// (E)     (E) (L)
//           \
//           (A)