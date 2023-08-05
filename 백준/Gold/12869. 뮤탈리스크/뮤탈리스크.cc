#include <iostream>
#include <queue>

using namespace std;

int n;
int navers[6][3] = 
{
    {-9,-3,-1},
    {-3,-9,-1},
    {-1,-3,-9},
    {-1,-9,-3},
    {-3,-1,-9},
    {-9,-1,-3},
};

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;
    vector<int> input;
    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        input.push_back(k);
    }
    while(input.size()<=3)   input.push_back(0);
    int visited[61][61][61];
    queue<vector<int>> q;
    q.push(input);      // SCV 체력들, 공격횟수

    int result = 60;
    while(!q.empty())
    {
        int arr[3];
        for(int i=0; i<3; i++)  arr[i] = q.front()[i];
        int atkCnt = q.front()[3];
        q.pop();

        bool allDead = true;
        for(int i=0; i<3; i++)
        {
            if(arr[i]>0)
            {
                allDead = false;
                break;
            }
        }
        if(allDead)
        {
            result = atkCnt;
            break;
        }

        for(int i=0; i<6; i++)
        {
            int temp[3];
            for(int j=0; j<3; j++)
            {
                temp[j] = navers[i][j] + arr[j];
                if(temp[j]<0)   temp[j] = 0;
            }
            if(visited[temp[0]][temp[1]][temp[2]])  continue;
            visited[temp[0]][temp[1]][temp[2]] = true;
            q.push({temp[0], temp[1], temp[2], atkCnt+1});
        }
    }
    cout<<result<<endl;
}