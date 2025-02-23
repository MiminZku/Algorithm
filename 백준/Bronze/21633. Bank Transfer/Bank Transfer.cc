#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    
    double ans = 25 + double(n) * 0.01;
    ans = max(ans, 100.0);
    ans = min(ans, 2000.0);
    cout.precision(3);
    printf("%.2lf\n", ans);
}