#include <iostream>

using namespace std;

string str;

int main()
{
    cin >> str;
    if(str.compare("fdsajkl;") == 0|| str.compare("jkl;fdsa") == 0)
    {
        cout << "in-out\n";
    }
    else if(str.compare("asdf;lkj") == 0|| str.compare(";lkjasdf") == 0)
    {
        cout << "out-in\n";
    }
    else if(str.compare("asdfjkl;") == 0)
    {
        cout << "stairs\n";
    }
    else if(str.compare(";lkjfdsa") == 0)
    {
        cout << "reverse\n";
    }
    else
    {
        cout << "molu\n";
    }
}