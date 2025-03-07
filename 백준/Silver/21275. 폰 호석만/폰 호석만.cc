#include <iostream>

using namespace std;

string A, B;

long long xAList[37];
long long xBList[37];

int MinJinsu(const string& str)
{
	int jinsu = 2;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			jinsu = max(jinsu, str[i] - 'a' + 11);
		}
		else
		{
			jinsu = max(jinsu, str[i] - '0' + 1);
		}
	}
	return jinsu;
}

long long Calculate(const string& str, int jinsu)
{
	long long x = 0;
	for (int i = str.length() - 1, mul = 1; i >= 0; --i, mul *= jinsu)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			int value = str[i] - 'a' + 10;
			x += value * mul;
		}
		else
		{
			int value = str[i] - '0';
			x += value * mul;
		}
	}
	return x;
}

int main()
{
	cin >> A >> B;
	
	int aJinsu = MinJinsu(A);
	
	for (int j = aJinsu; j <= 36; ++j)
	{
		xAList[j] = Calculate(A, j);
	}

	int bJinsu = MinJinsu(B);
	for (int j = bJinsu; j <= 36; ++j)
	{
		xBList[j] = Calculate(B, j);
	}

	int cnt = 0;
	int ansX, ansA, ansB;
	for (int a = aJinsu; a <= 36; ++a)
	{
		for (int b = bJinsu; b <= 36; ++b)
		{
			if (a == b)	continue;

			if (xAList[a] == xBList[b])
			{
				++cnt;
				ansX = xAList[a];
				ansA = a;
				ansB = b;
			}
		}
	}

	if (cnt == 0)
	{
		cout << "Impossible\n";
	}
	else if (cnt > 1)
	{
		cout << "Multiple\n";
	}
	else
	{
		cout << ansX << ' ' << ansA << ' ' << ansB << endl;
	}
}