#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m, k;
vector<ll> nums;
vector<ll> sumTree;

ll Init(int node, int left, int right)
{
	int mid = (left + right) / 2;

	if (left == right)
	{
		return sumTree[node] = nums[mid];
	}
	return sumTree[node] =
		Init(node * 2, left, mid) + Init(node * 2 + 1, mid + 1, right);
}

void Update(int node, int left, int right, int idx, ll newNum)
{
	if (idx < left || idx > right)	return;

	sumTree[node] += (newNum - nums[idx]);

	if (left == right)
	{
		return;
	}
	int mid = (left + right) / 2;
	Update(node * 2, left, mid, idx, newNum);
	Update(node * 2 + 1, mid + 1, right, idx, newNum);
}

ll Sum(int node, int left, int right, int sumStart, int sumEnd)
{
	if (sumStart > right || sumEnd < left)
	{
		return 0;
	}

	if (sumStart <= left && right <= sumEnd)
	{
		return sumTree[node];
	}

	int mid = (left + right) / 2;
	return Sum(node * 2, left, mid, sumStart, sumEnd)
		+ Sum(node * 2 + 1, mid + 1, right, sumStart, sumEnd);
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	nums.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	sumTree.resize(4 * n, 0);
	Init(1, 0, n - 1);

	for (ll i = 0, a, b, c; i < (m + k); ++i)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			Update(1, 0, n - 1, b - 1, c);
			nums[b - 1] = c;
		}
		else
		{
			cout << Sum(1, 0, n - 1, b - 1, c - 1) << '\n';
		}
	}
}