#include <iostream>
#include <set>

using namespace std;


int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
        int k;
        multiset<int> ms;
		cin >> k;
		char op;
		int n;
		for (int i = 0; i < k; ++i)
		{
			cin >> op >> n;

			if (op == 'I')
			{
				ms.insert(n);
			}
			else
			{
				if (ms.empty())	continue;

				if (n == 1)
				{
					auto iter = --ms.end();
					ms.erase(iter);
				}
				else 
				{
					auto iter = ms.begin();
					ms.erase(iter);
				}
			}
		}

		if (ms.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			auto iter = --ms.end();
			cout << *iter << ' ';
			iter = ms.begin();
			cout << *iter << endl;
		}
	}
}