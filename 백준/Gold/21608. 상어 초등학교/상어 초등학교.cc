#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define fastio cin.tie(nullptr); ios::sync_with_stdio(false);

int n;
pair<int,int> navers[4] = {{-1,0},{1,0},{0,-1},{0,1}};
int seats[20][20];
int likes[401][4];  // likes[i] : i번 학생이 좋아하는 학생들의 번호 배열

bool Likes(int s1, int s2){
    for(int s: likes[s1]){
        if(s==s2)   return true;
    }
    return false;
}
int CountLikes(int r, int c, int num){
    int count = 0;
    for(pair<int,int> pos : navers){
        int nr = r+pos.first;
        int nc = c+pos.second;
        if(nr<0 || nc<0 || nr>=n || nc>=n)  continue;
        if(Likes(num, seats[nr][nc]))  count++;
    }
    return count;
}
int CountEmpties(int r, int c){
    int count = 0;
    for(pair<int,int> pos : navers){
        int nr = r+pos.first;
        int nc = c+pos.second;
        if(nr<0 || nc<0 || nr>=n || nc>=n)  continue;
        if(!seats[nr][nc])  count++;
    }
    return count;
}

void SeatOne(int num){
    int r,c;
    int maxLikes = 0; int maxEmpties = 0;
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(seats[i][j]) continue;   // 빈자리 아니면 넘어감
            int likes = CountLikes(i,j,num);
            if(likes > maxLikes){
                maxLikes = likes;
                maxEmpties = CountEmpties(i,j);
                r = i; c = j;
            }
            else if(likes == maxLikes){
                int empties = CountEmpties(i,j);
                if(empties >= maxEmpties){
                    maxEmpties = empties;
                    r = i;  c = j;
                }
            }
        }
    }
    seats[r][c] = num;
}
void SeatStudents(vector<int>& seq){
    for(int num : seq){
        SeatOne(num);
    }
}

int GetTotalSatisfaction(){
    int sum=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int count = CountLikes(i,j,seats[i][j]);
            if(count)
                sum += pow(10,count-1);
        }
    }
    return sum;
}

int main(){
    cin>>n;
    vector<int> seq;
    for(int i=1; i<=n*n; i++){
        int sNum;
        cin>>sNum;
        seq.push_back(sNum);
        for(int j=0; j<4; j++){
            int sNumLike;
            cin>>sNumLike;
            likes[sNum][j] = sNumLike;
        }
    }
    SeatStudents(seq);
    cout<<GetTotalSatisfaction()<<'\n';
}