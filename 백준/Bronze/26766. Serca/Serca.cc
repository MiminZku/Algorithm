#include <iostream>

using namespace std;

void PrintHeart()
{
    cout<<" @@@   @@@ \n";
    cout<<"@   @ @   @\n";
    cout<<"@    @    @\n";
    cout<<"@         @\n";
    cout<<" @       @ \n";
    cout<<"  @     @  \n";
    cout<<"   @   @   \n";
    cout<<"    @ @    \n";
    cout<<"     @     \n";
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int i;
    cin>>i;

    while(i--)
    {
        PrintHeart();
    }
}