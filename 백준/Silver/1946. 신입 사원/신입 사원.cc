#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> scores[100000];
int minScore[100000];   // [i] : 0~i번 index중 면접 최고 순위

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> scores[i].first >> scores[i].second;
        }

        sort(scores, scores + n);

        minScore[0] = scores[0].second;
        for (int i = 1; i < n; ++i)
        {
            minScore[i] = min(minScore[i - 1], scores[i].second);
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (scores[i].second > minScore[i])  continue;
            
            ++cnt;
        }
        cout << cnt << endl;
    }
}