#include <iostream>

using namespace std;

int n;
long long b;
int mat[5][5];

void Mul(const int matA[5][5], const int matB[5][5], int out[5][5])
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int tmp = 0;
            for (int k = 0; k < n; ++k)
            {
                tmp += matA[i][k] * matB[k][j];
            }
            out[i][j] = tmp % 1000;
        }
    }
}

void Pow(long long cnt, int out[5][5])
{
    if (cnt == 1)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                out[i][j] = mat[i][j] % 1000;
            }
        }
        return;
    }

    int tmp[5][5];
    if (cnt % 2)
    {
        Pow(cnt - 1, tmp);
        Mul(tmp, mat, out);
    }
    else
    {
        Pow(cnt / 2, tmp);
        Mul(tmp, tmp, out);
    }
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n >> b;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mat[i][j];
        }
    }

    int ans[5][5];
    Pow(b, ans);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}