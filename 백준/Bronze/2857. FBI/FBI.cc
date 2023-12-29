#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    bool hasFBI = false;
    for(int j=1; j<=5; j++)
    {
        string str;
        cin>>str;

        for(int i=0; i<str.length()-2; i++)
        {
            if(str[i] == 'F' && str[i+1] == 'B' && str[i+2] == 'I')
            {
                hasFBI = true;
                cout<<j<<'\n';
                break;
            }
        }
    }
    if(!hasFBI) cout<<"HE GOT AWAY!\n";
}