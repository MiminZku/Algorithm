#include <iostream>
#include <vector>

using namespace std;

int DFS(int idx, int teamNum, const vector<int>& wish, vector<int>& team)
{
    team[idx] = teamNum;
    if (team[wish[idx]])
    {
        team[idx] = -1;
        return wish[idx];
    }
    
    int lastIdx = DFS(wish[idx], teamNum, wish, team);
    if (lastIdx == idx)
    {
        int next = wish[idx];
        while (next != idx)
        {
            team[next] = teamNum;
            next = wish[next];
        }
    }
    else
    {
        team[idx] = -1;
    }

    return lastIdx;
}

int main() 
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> wish(n + 1);
        vector<int> team(n + 1, 0);
        int teamNum = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> wish[i];
            if (i == wish[i])
            {
                team[i] = teamNum++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (team[i] != 0)    continue;
            DFS(i, teamNum++, wish, team);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (team[i] < 0)
            {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}