#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> nArr;
vector<int> mArr;
int ans;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		if (k > 0)
		{
			nArr.push_back(k);
		}
		else
		{
			mArr.push_back(k);
		}
	}
	sort(nArr.begin(), nArr.end(), greater<int>());
	sort(mArr.begin(), mArr.end());

	for (int i = 0; i < nArr.size(); i += 2)
	{
		int a = i, b = i + 1;
		if (b >= nArr.size())
		{
			ans += nArr[a];
			break;
		}

		ans += max(nArr[a] * nArr[b], nArr[a] + nArr[b]);
	}

	for (int i = 0; i < mArr.size(); i += 2)
	{
		int a = i, b = i + 1;
		if (b >= mArr.size())
		{
			ans += mArr[a];
			break;
		}

		ans += mArr[a] * mArr[b];
	}

	cout << ans << endl;
}