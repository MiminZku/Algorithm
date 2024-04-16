#include <iostream>

using namespace std;

string str = "WelcomeToSMUPC";

int main()
{
    int n;
    cin>>n;
    cout<<str[(n-1)%14]<<endl;
}