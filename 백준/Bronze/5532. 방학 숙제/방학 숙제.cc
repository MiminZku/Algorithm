#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int L,A,B,C,D;
    cin>>L>>A>>B>>C>>D;

    int lan = A / C;
    if(A % C)   lan += 1;

    int mth = B / D;
    if(B % D)   mth += 1;

    cout << L - max(lan, mth) << endl;
}