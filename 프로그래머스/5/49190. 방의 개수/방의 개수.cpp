#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int cnt;
int ans;
map<pair<float, float>, bool> visited;
map<pair<float, float>, set<pair<float, float>>> navers;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void makeEdges(vector<int>& arr, int x, int y)
{
    if(cnt == arr.size()) return;
    
    float nextX = x + dx[arr[cnt]];
    float nextY = y + dy[arr[cnt]];
    
    if(arr[cnt] % 2)
    {
        float midX = (x + nextX) / 2.f, midY = (y + nextY) / 2.f;
        
        navers[{x, y}].insert({midX, midY});
        navers[{midX, midY}].insert({x, y});
        
        navers[{nextX, nextY}].insert({midX, midY});
        navers[{midX, midY}].insert({nextX, nextY});        
    }
    else
    {
        navers[{x, y}].insert({nextX, nextY});
        navers[{nextX, nextY}].insert({x, y});
    }
    
    ++cnt;
    
    makeEdges(arr, nextX, nextY);
}

void dfs(float x, float y, float prevX, float prevY)
{
    visited[{x, y}] = true;
    
    for(auto& naver : navers[{x, y}])
    {
        if(naver.first == prevX && naver.second == prevY) continue;
        if(visited[{naver.first, naver.second}])
        {
            ++ans;
            continue;
        }
        dfs(naver.first, naver.second, x, y);
    }    
}

int solution(vector<int> arrows) {
    visited[{0,0}] = true;
    makeEdges(arrows, 0, 0);
    dfs(0, 0, 0, 0);
    return ans / 2;
}