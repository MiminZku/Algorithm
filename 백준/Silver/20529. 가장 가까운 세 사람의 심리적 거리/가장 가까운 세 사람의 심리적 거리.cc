#include <iostream>
#include <cstring>

using namespace std;

int t,n;
int minimum;
int idx[3];
int isExist[16];
int dist[16][16] = {
    0,1,1,2, 1,2,2,3, 1,2,2,3, 2,3,3,4,
    1,0,2,1, 2,1,3,2, 2,1,3,2, 3,2,4,3,
    1,2,0,1, 2,3,1,2, 2,3,1,2, 3,4,2,3,
    2,1,1,0, 3,2,2,1, 3,2,2,1, 4,3,3,2,

    1,2,2,3, 0,1,1,2, 2,3,3,4, 1,2,2,3,
    2,1,3,2, 1,0,2,1, 3,2,4,3, 2,1,3,2,
    2,3,1,2, 1,2,0,1, 3,4,2,3, 2,3,1,2,
    3,2,2,1, 2,1,1,0, 4,3,3,2, 3,2,2,1,

    1,2,2,3, 2,3,3,4, 0,1,1,2, 1,2,2,3,
    2,1,3,2, 3,2,4,3, 1,0,2,1, 2,1,3,2,
    2,3,1,2, 3,4,2,3, 1,2,0,1, 2,3,1,2,
    3,2,2,1, 4,3,3,2, 2,1,1,0, 3,2,2,1,

    2,3,3,4, 1,2,2,3, 1,2,2,3, 0,1,1,2,
    3,2,4,3, 2,1,3,2, 2,1,3,2, 1,0,2,1,
    3,4,2,3, 2,3,1,2, 2,3,1,2, 1,2,0,1,
    4,3,3,2, 3,2,2,1, 3,2,2,1, 2,1,1,0,
};

int GetDistance(){
    return dist[idx[0]][idx[1]] 
    + dist[idx[1]][idx[2]] 
    + dist[idx[2]][idx[0]];
}
void Solve(int level, int start){
    if(level == 3){
        int distance = GetDistance();
        if(minimum > distance)  minimum = distance;
    }
    else{
        for(int i=start; i<16; i++){
            if(!isExist[i]) continue;
            idx[level] = i;
            isExist[i]--;
            Solve(level+1, i);
            isExist[i]++;
        }
    }
}
int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        char mbti[5];
        for(int i=0; i<16; i++) isExist[i] = 0;
        for(int i=0; i<n; i++){
            cin>>mbti;
                 if(!strcmp(mbti,"ESTJ"))   isExist[0]++;
            else if(!strcmp(mbti,"ESTP"))   isExist[1]++;
            else if(!strcmp(mbti,"ESFJ"))   isExist[2]++;
            else if(!strcmp(mbti,"ESFP"))   isExist[3]++;

            else if(!strcmp(mbti,"ENTJ"))   isExist[4]++;
            else if(!strcmp(mbti,"ENTP"))   isExist[5]++;
            else if(!strcmp(mbti,"ENFJ"))   isExist[6]++;
            else if(!strcmp(mbti,"ENFP"))   isExist[7]++;

            else if(!strcmp(mbti,"ISTJ"))   isExist[8]++;
            else if(!strcmp(mbti,"ISTP"))   isExist[9]++;
            else if(!strcmp(mbti,"ISFJ"))   isExist[10]++;
            else if(!strcmp(mbti,"ISFP"))   isExist[11]++;

            else if(!strcmp(mbti,"INTJ"))   isExist[12]++;
            else if(!strcmp(mbti,"INTP"))   isExist[13]++;
            else if(!strcmp(mbti,"INFJ"))   isExist[14]++;
            else if(!strcmp(mbti,"INFP"))   isExist[15]++;
        }
        minimum = 10;
        Solve(0, 0);
        cout<<minimum<<'\n';
    }
}