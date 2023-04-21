#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int n;  priority_queue<int> pq;
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d",&x);
        if(x){
            pq.push(x);
        }
        else{
            int temp;
            if(pq.size()){
                temp = pq.top();
                pq.pop();
            }
            else{
                temp = 0;
            }
            printf("%d\n",temp);
        }
    }
}