#include <iostream>

using namespace std;

string str;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    getline(cin, str);

    bool check = true;
    if(str[0] == '"' && str[str.length()-1] == '"')
    {
        for(int i=1; i<str.length()-1; ++i)
        {
            check = false;
            cout << str[i];
        }
    }    
    if(check)
    {
        cout << "CE";
    }
    cout << endl;
}