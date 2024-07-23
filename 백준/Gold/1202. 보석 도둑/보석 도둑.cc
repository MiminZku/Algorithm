#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define MAX 300001

int N;
int K;

pair<int, int> jewels[MAX];
int bag[MAX];
priority_queue<int> pq;

long long solve() 
{
    sort(jewels, jewels + N);
    sort(bag, bag + K);

    long long sum = 0;
    int idx = 0;
    for (int i = 0; i < K; ++i) 
    {
        while (idx < N && bag[i] >= jewels[idx].first)
        {
            pq.push(jewels[idx].second);
            idx++;
        }
        if (!pq.empty()) 
        {
            sum += pq.top();
            pq.pop();
        }
    }
    return sum;
}

int main() 
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) 
    {
        cin >> jewels[i].first >> jewels[i].second;
    }
    for (int i = 0; i < K; ++i) 
    {
        cin >> bag[i];
    }
    cout << solve() << endl;
}