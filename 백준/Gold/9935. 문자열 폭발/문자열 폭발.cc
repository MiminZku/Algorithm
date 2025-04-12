#include <iostream>
#include <string>
#include <vector>

using namespace std; 

string str, bomb;
vector<char> vec;

int main()
{
    ios::sync_with_stdio(false);
	cin >> str >> bomb;
	int bombLen = bomb.length();

	for (char ch : str)
	{
		vec.push_back(ch);

		if (ch == bomb[bombLen - 1])
		{
			if (vec.size() < bombLen)	continue;

			bool isBomb = true;
			for (int i = 0; i < bombLen; ++i)
			{
				if (vec[vec.size() - bombLen + i] != bomb[i])
				{
					isBomb = false;
					break;
				}
			}

			if (isBomb)
			{
				for (int i = 0; i < bombLen; ++i)
				{
					vec.pop_back();
				}
			}			
		}
	}

	if (vec.size() == 0)
	{
		cout << "FRULA\n";
	}
	else
	{
		for (char ch : vec)
		{
			cout << ch;
		}
		cout << endl;
	}
}