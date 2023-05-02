#include <cstdio>
#include <vector>
#include <set>

using namespace std;

typedef pair<char, int> Cmd;

void Solve(vector<Cmd>& cmd_list){
    multiset<int> ms;
    for (Cmd cmd : cmd_list){
        if(cmd.first == 'I'){
            ms.insert(cmd.second);
        }
        else if(cmd.first == 'D'){
            if(ms.empty())   continue;
            if(cmd.second == 1){
                ms.erase(--ms.end());
            }
            else if(cmd.second == -1){
                ms.erase(ms.begin());
            }
        }
    }
    if(ms.empty())  printf("EMPTY\n");
    else{
        printf("%d %d\n",(*--ms.end()),(*ms.begin()));
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        int k;
        scanf("%d", &k);
        vector<Cmd> cmd_list;
        for(int j=0; j<k; j++){
            int c,n;
            scanf(" %c %d",&c, &n);
            cmd_list.push_back({c,n});
        }
        Solve(cmd_list);
    }
}

