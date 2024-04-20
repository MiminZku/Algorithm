#include <iostream>

using namespace std;

int n;
int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin>>n;
    cin.ignore();

    string str;
    while(n--)
    {
        cin>>str;
        if(!str.compare("Algorithm"))                   cout<<"204\n";
        else if(!str.compare("DataAnalysis"))           cout<<"207\n";
        else if(!str.compare("ArtificialIntelligence")) cout<<"302\n";
        else if(!str.compare("CyberSecurity"))          cout<<"B101\n";
        else if(!str.compare("Network"))                cout<<"303\n";
        else if(!str.compare("Startup"))                cout<<"501\n";
        else if(!str.compare("TestStrategy"))           cout<<"105\n";
    }
}