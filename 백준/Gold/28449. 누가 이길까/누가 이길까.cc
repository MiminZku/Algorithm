#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    vector<int> hi(n);
    vector<int> arc(m);
 
    for (int& ele : hi) cin >> ele;
    for (int& ele : arc) cin >> ele;
 
    sort(hi.begin(), hi.end());
    sort(arc.begin(), arc.end());
 
 
    long long hi_win = 0;
    long long draw = 0;
    long long arc_win = 0;
 
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        int e = m - 1;
 
        // 해당 타겟을 기준으로 무승부인 지점을 찾는다.
        int target = hi[i];
 
        int left_idx = m;
 
        while (s <= e)
        {
            int mid = (s + e) / 2;
 
            if (arc[mid] >= target)
            {
                left_idx = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
 
 
        int right_idx = -1;
 
        s = 0;
        e = m - 1;
 
        while (s <= e)
        {
            int mid = (s + e) / 2;
            
            if (arc[mid] <= target)
            {
                right_idx = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
 
        hi_win += left_idx;
        draw += (right_idx - left_idx + 1);
        arc_win += (m - right_idx - 1);
    }
 
    cout << hi_win << " " << arc_win << " " << draw;
 
    return 0;
}