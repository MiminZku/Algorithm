#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int t;
int n;

struct TrieNode
{
	bool isEnd = false;
	TrieNode* children[10];
};

class Trie
{
	TrieNode* root;

public:
	Trie()
	{
		root = new TrieNode();
	}

	void Insert(const string& str, int index)
	{
		TrieNode* node = root;
		for (char c : str)
		{
			if (node->children[c - '0'] == nullptr)
			{
				node->children[c - '0'] = new TrieNode();
			}
			node = node->children[c - '0'];
		}
		node->isEnd = true;
	}

	bool Find(const string& str)
	{
		TrieNode* node = root;

		for (char c : str)
		{
			if (node->isEnd)
			{
				return true;
			}

			if (node->children[c - '0'] == nullptr)
			{
				break;
			}
			node = node->children[c - '0'];
		}
		return false;
	}
};

bool IsConsistent(const vector<string>& inputs)
{
	Trie trie;

	for (int i = 0; i < inputs.size(); ++i)
	{
		if (trie.Find(inputs[i]))
		{
			return false;
		}

		trie.Insert(inputs[i], i + 1);
	}
	return true;
}

bool Cmp(const string& s1, const string& s2)
{
	if (s1.length() == s2.length())
	{
		return s1 < s2;
	}
	return s1.length() < s2.length();
}

int main()
{
	cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);

	cin >> t;
	while (t--)
	{
		cin >> n;
		cin.ignore();

		vector<string> inputs;
		inputs.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> inputs[i];
		}
		sort(inputs.begin(), inputs.end(), Cmp);

		cout << (IsConsistent(inputs) ? "YES\n" : "NO\n");
	}
}
