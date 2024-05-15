#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    for(int i=0; i<4; ++i)
    {
        int k;
        cin>>k;
        sum += k;
    }

    cout<<sum/60<<endl;
    cout<<sum%60<<endl;
}