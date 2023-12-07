#include <iostream>

using namespace std;

int main()
{
    string str;

    cin>>str;
    str.append("|");

    int cMajor = 0;
    int aMinor = 0;
    
    char first = 0;
    char last = str[str.length()-2];

    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == '|')
        {
            if(first == 'C' || first == 'F' || first == 'G')
            {
                cMajor++;
            }
            else if(first == 'A' || first == 'D' || first == 'E')
            {
                aMinor++;
            }
            first = 0;
            continue;
        }
        if(first == 0)
        {
            first = str[i];
        }
    }

    if(cMajor > aMinor)
    {
        cout<<"C-major\n";
    }
    else if(cMajor < aMinor)
    {
        cout<<"A-minor\n";
    }
    else
    {
        if(last == 'C' || last == 'F' || last == 'G')
        {
            cout<<"C-major\n";
        }
        else if(last == 'A' || last == 'D' || last == 'E')
        {
            cout<<"A-minor\n";
        }
        else
        {
            cout<<"wtf\n";
        }
    }
}