#include <iostream>

using namespace std;

int p, q;
bool visited[100][100][2];
int memo[100][100][2];

int Recur(int rowLen, int colLen, bool isBlack)
{
	if (rowLen == 0 || colLen == 0)
	{
		return 0;
	}
	if (rowLen == 1 && colLen == 1)
	{
		return -1;
	}

	if (visited[rowLen][colLen][isBlack])
	{
		return memo[rowLen][colLen][isBlack];
	}

	int ret = -10000;
	for (int i = 1; i <= colLen; ++i)
	{
		int tmp = 0;
		if (i % 2 == 1 && rowLen % 2 == 1)
		{
			if (isBlack)
			{
				tmp += 1;
			}
			else
			{
				tmp -= 1;
			}
		}
		ret = max(ret, tmp - Recur(colLen - i, rowLen, (i % 2) ? !isBlack : isBlack));
	}

	visited[rowLen][colLen][isBlack] = true;
	return memo[rowLen][colLen][isBlack] = ret;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> p >> q;

    if(p == 1 && q == 1)
    {
        cout << 1 << endl;
        return 0;
    }
	cout << Recur(p, q, true) << endl;
}