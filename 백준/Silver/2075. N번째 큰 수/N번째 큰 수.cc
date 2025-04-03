#include <iostream>
#include <algorithm>

using namespace std;

int n;
int mat[2250000];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n * n; ++i)
	{
		cin >> mat[i];
	}

	sort(mat, mat + n * n);

	cout << mat[n * n - n] << endl;
}