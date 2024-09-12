#include <iostream>

using namespace std;

int n, k;
int cnt;
int path[10];
bool flag;

void Recur(int level, int total)
{
    if(flag) return;
    if(total > n)   return;
    if(total == n)
    {
        ++cnt;
        if(cnt == k)
        {
            flag = true;
            cout<<path[0];
            for(int i=1; i<level; ++i)
            {
                cout<<'+'<<path[i];
            }
            cout<<endl;
        }
        return;    // 이거 안써줘서 틀림.. 병신인가?
    }
    for(int i=1; i<=3; ++i)
    {
        path[level] = i;
        Recur(level + 1, total + i);
    }
}

int main()
{
    cin>>n>>k;
    
    Recur(0, 0);

    if(!flag)    cout<<"-1\n";
}