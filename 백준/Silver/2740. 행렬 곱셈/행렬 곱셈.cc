#include <iostream>

using namespace std;

int n, m, k;
int matA[100][100];
int matB[100][100];

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin >> matA[i][j];
        }
    }
    cin >> m >> k;
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<k; ++j)
        {
            cin >> matB[i][j];
        }
    }

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<k; ++j)
        {
            int tmp = 0;
            for(int l=0; l<m; ++l)
            {
                tmp += matA[i][l] * matB[l][j];
            }
            cout << tmp << ' ';
        }
        cout << '\n';
    }
}