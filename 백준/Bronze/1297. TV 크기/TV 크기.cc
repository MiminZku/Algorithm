#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double d,h,w;
    cin>>d>>h>>w;
    double x = sqrt(d*d / (h*h+w*w));
    cout<<int(h*x)<<' '<<int(w*x)<<endl;
}