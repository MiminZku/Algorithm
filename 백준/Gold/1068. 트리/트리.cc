#include <iostream>
#include <vector>

using namespace std;

int n, del, root;
vector<int> childs[50];
int ans;

void DFS(int cur)
{
	int childNum = 0;
	
	for (int child : childs[cur])
	{
		if (child == del) continue;
		childNum++;
		DFS(child);
	}
	
	if (childNum == 0)
	{
		ans++;
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0, k; i < n; ++i)
	{
		cin >> k;
		if (k == -1)
		{
			root = i;
		}
		else
		{
			childs[k].push_back(i);
		}
	}
	cin >> del;

	if (root == del)
	{
		cout << 0 << endl;
		return 0;
	}
	DFS(root);

	cout << ans << endl;
}