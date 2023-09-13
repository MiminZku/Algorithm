#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int a,b;
int m;

int main()
{
    cin>>a>>b;
    cin>>m;
    int sum = 0;
    for(int i=m-1 ; i>=0; i--)
    {
        int k;
        cin>>k;
        sum += pow(a,i)*k;
    }

    stack<int> remainders;
    while(true)
    {
        int quotient = sum / b;
        remainders.push(sum % b);
        sum = quotient;
        if(quotient == 0)   break;
    }

    while(!remainders.empty())
    {
        cout<<remainders.top()<<' ';
        remainders.pop();
    }
    cout<<'\n';
}