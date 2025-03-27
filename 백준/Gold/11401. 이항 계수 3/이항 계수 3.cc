#include <iostream>

using namespace std;

#define DIV 1000000007

long long Mul(long long n, long long m)
{
    if (m == 0)    return 1;

    long long ret = Mul(n, m / 2);
    ret = (ret % DIV) * (ret % DIV) % DIV;
    if (m % 2)
    {
        ret *= (n % DIV);
    }

    return ret %= DIV;
}

long long Sol(int n, int k) 
{
    if (k == 0 || n == k)
    {
        return 1;
    }
    if (k == 1 || n - k == 1)
    {
        return n;
    }

    long long a = n, b = k;
    for (int i = 1; i < k; i++)
    {
        a = a * (n - i) % DIV;
        b = b * i % DIV;
    }
    
    return a * Mul(b, DIV - 2) % DIV;
}

int main()
{
    long long n, k;
    cin >> n >> k;

    cout << Sol(n, k) << endl;
}

/*

페르마의 소정리 이용
참고 블로그 :
https://velog.io/@junttang/BOJ-11401-%EC%9D%B4%ED%95%AD-%EA%B3%84%EC%88%98-3-%ED%95%B4%EA%B2%B0-%EC%A0%84%EB%9E%B5-C

*/