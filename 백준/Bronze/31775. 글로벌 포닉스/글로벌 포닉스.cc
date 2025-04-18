#include <iostream>

using namespace std;

string a, b, c;
bool check[3];

int main()
{
    cin >> a >> b >> c;
    if(a[0] == 'l' || b[0] == 'l' || c[0] == 'l')
    {
        check[0] = true;
    }
    if(a[0] == 'k' || b[0] == 'k' || c[0] == 'k')
    {
        check[1] = true;
    }
    if(a[0] == 'p' || b[0] == 'p' || c[0] == 'p')
    {
        check[2] = true;
    }
    
    bool isGlobal = true;
    for(int i=0; i<3; ++i)
    {
        if(check[i] == false)
        {
            isGlobal = false;
            break;
        }
    }

    cout << (isGlobal ? "GLOBAL\n" : "PONIX\n");
}