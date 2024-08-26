#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> vec(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
 
    string temp;
 
    for (int i = 1; i < n + 1; i++)
    {
        cin >> temp;
        for (int j = 1; j < m + 1; j++)
        {
            if (temp[j - 1] == '0') vec[i][j] = 1;
            else if (temp[j - 1] == '1') vec[i][j] = 0;
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + vec[i][j];
        }
    } 
 
    int ans = 0;
    // 열 2개 선택
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = i; j < m + 1; j++)
        {
            // 행을 따라 내려가면서
            int cnt = 0;
            for (int k = 1; k < n + 1; k++)
            {
                int temp = prefix[k][j] - prefix[k][i - 1] - prefix[k - 1][j] + prefix[k - 1][i - 1];
                if (temp == j - i + 1)
                {
                    cnt += temp;
                    ans = max(ans, cnt);
                }
                else
                {
                    cnt = 0;
                }
            }
        }
    } 
    cout << ans << endl;
}
