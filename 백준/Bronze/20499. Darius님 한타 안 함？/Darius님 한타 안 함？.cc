#include <iostream>
#include <cstring>

using namespace std;

char str[10];
int arr[3];

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>str;
    char* token = strtok(str, "/");;
    int idx = 0;
    while (NULL != token)
    {
        arr[idx++] = stoi(token);
        token = strtok(NULL, "/");
    }

    if(arr[1] == 0 || arr[1] > (arr[0] + arr[2]))
        cout<<"hasu\n";
    else
        cout<<"gosu\n";
}