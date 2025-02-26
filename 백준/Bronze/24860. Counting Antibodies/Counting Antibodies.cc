#include <iostream>

using namespace std;

long long vk, jk, vl, jl, vh, dh, jh;

int main()
{
    cin >> vk >> jk >> vl >> jl >> vh >> dh >> jh;

    long long ans = vh * dh * jh;
    ans *= vk * jk;
    ans += vh * dh * jh * vl * jl;

    cout << ans << endl;
}