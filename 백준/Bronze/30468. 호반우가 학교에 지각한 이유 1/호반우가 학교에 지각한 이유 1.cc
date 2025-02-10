#include <iostream>

using namespace std;

int a, b, c, d;
int n;

int main()
{
    cin >> a >> b >> c >> d >> n;

    int total = a + b + c + d;
    cout << max(0, n * 4 - total) << endl;
}