#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LIS(const vector<int>& nums) 
{
    if (nums.empty()) return 0;

    vector<int> lis;
    
    for (int num : nums) 
    {
        // 이분 탐색을 통해 lis에서 num의 위치 찾기
        auto it = lower_bound(lis.begin(), lis.end(), num);
        
        // num이 lis의 끝보다 크면 추가
        if (it == lis.end()) 
        {
            lis.push_back(num);
        }
        // 아니면 해당 위치에 있는 값을 num으로 대체
        else 
        {
            *it = num;
        }
    }
    
    return lis.size();
}

int main() 
{
    cin.tie(0); ios::sync_with_stdio(0);
    vector<int> nums;
    int n;

    cin >> n;
    nums.resize(n);
    
    for (int i = 0; i < n; ++i) 
    {
        cin >> nums[i];     
    }

    cout << LIS(nums) << endl;
}