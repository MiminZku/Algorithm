#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) 
{
    long long longest = 0;
    for(int t : times)
    {
        if(t > longest)
        {
            longest = t;
        }
    }
    
    long long answer = 0;
    long long l = 1, r = longest * n;
    while(l <= r)
    {
        long long mid = (l + r) / 2;
        long long cnt = 0;
        for(int t : times)
        {
            cnt += mid / t;
        }
        
        if(cnt < n)
        {
            l = mid + 1;
        }
        else
        {
            answer = mid;
            r = mid - 1;
        }
    }
    return answer;
}