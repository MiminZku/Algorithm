#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int i;
    cin>>i;

    if(i >= 620)
    {
        cout<<"Red\n";
    }
    else if(i >= 590)
    {
        cout<<"Orange\n";
    }
    else if(i >= 570)
    {
        cout<<"Yellow\n";        
    }
    else if(i >= 495)
    {
        cout<<"Green\n";        
    }
    else if(i >= 450)
    {
        cout<<"Blue\n";        
    }
    else if(i >= 425)
    {
        cout<<"Indigo\n";        
    }
    else
    {
        cout<<"Violet\n";
    }
}