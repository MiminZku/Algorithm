#include <iostream>
#include <vector>

using namespace std;

int parent[1'000'001];

int Find(int a)
{
	if (a == parent[a])
	{
		return a;
	}
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	int aParent = Find(a);
	int bParent = Find(b);
	if (aParent != bParent)
	{
		parent[aParent] = bParent;
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);


	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i)
	{
		parent[i] = i;
	}

	int op, a, b;
	while (m--)
	{
		cin >> op >> a >> b;
		if (op)
		{
			if (Find(a) == Find(b))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
		else
		{
			Union(a, b);
		}
	}
}