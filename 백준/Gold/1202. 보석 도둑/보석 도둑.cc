#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;

pair<int, int> jewels[300'001];
int bag[300'001];

int main() 
{
    cin.tie(nullptr); 
    ios::sync_with_stdio(false);
    
    cin >> n >> k;
    for (int i = 0; i < n; ++i) 
    {
        cin >> jewels[i].first >> jewels[i].second;
    }
    for (int i = 0; i < k; ++i) 
    {
        cin >> bag[i];
    }

    sort(jewels, jewels + n);
    sort(bag, bag + k);

    priority_queue<int> pq;
    int idx = 0;
    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        while (idx < n && jewels[idx].first <= bag[i])
        {
            pq.push(jewels[idx].second);
            idx++;
        }
        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
}