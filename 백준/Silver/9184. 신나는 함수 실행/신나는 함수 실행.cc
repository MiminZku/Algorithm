#include <iostream>

using namespace std;

int memo[21][21][21];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	for(int i=0; i<=20; ++i)
	{
		for(int j=0; j<=20; ++j)
		{
			for(int k=0; k<=20; ++k)
			{
				if(i == 0 || j == 0 || k == 0)
				{
					memo[i][j][k] = 1;
				}
			}
		}
	}

	for(int i=1; i<=20; ++i)
	{
		for(int j=1; j<=20; ++j)
		{
			for(int k=1; k<=20; ++k)
			{
				if(i < j && j < k)
				{
					memo[i][j][k] = 
						memo[i][j][k-1] + memo[i][j-1][k-1] - memo[i][j-1][k];
				}
				else
				{
					memo[i][j][k] = 
						memo[i-1][j][k] + memo[i-1][j-1][k] + memo[i-1][j][k-1] - memo[i-1][j-1][k-1];
				}
			}
		}
	}

	int a, b, c;
	while(true)
	{
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1)
		{
			break;
		}

		int res = 0;
		if(a <= 0 || b <= 0 || c <= 0)
		{
			res = memo[0][0][0];
		}
		else if(a > 20 || b > 20 || c > 20)
		{
			res = memo[20][20][20];
		}
		else
		{
			res = memo[a][b][c];
		}

		cout << "w(" << a << ", " << b << ", " << c << ") = " << res << '\n';
	}
}