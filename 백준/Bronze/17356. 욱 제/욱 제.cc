#include <iostream>
#include <cmath>

using namespace std;

int a, b;

int main()
{
    cin>>a>>b;
    double m = (b - a) / 400.0;
    cout<<1.0/(1 + pow(10,m))<<endl;
}