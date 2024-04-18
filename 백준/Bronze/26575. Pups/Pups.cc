#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        double d,f,p;
        cin>>d>>f>>p;

        cout<<"$";
        printf("%.2f\n", d*f*p);
    }
}