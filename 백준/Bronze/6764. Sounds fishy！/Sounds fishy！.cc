#include <iostream>

using namespace std;

int arr[4];

int main()
{
    for(int i=0; i<4; ++i)  cin>>arr[i];

    if(arr[0] < arr[1])
    {
        if(arr[1] < arr[2] && arr[2] < arr[3])
        {
            cout<<"Fish Rising\n";
            return 0;
        }
    }
    else if(arr[0] > arr[1])
    {
        if(arr[1] > arr[2] && arr[2] > arr[3])
        {
            cout<<"Fish Diving\n";
            return 0;
        }
    }
    else
    {
        if(arr[1] == arr[2] && arr[2] == arr[3])
        {
            cout<<"Fish At Constant Depth\n";
            return 0;
        }
    }

    cout<<"No Fish\n";
}