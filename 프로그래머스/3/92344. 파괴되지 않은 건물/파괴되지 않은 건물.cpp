#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) 
{
    int n = board.size();
    int m = board[0].size();
    
    vector<vector<int>> cumSum(n+1, vector<int>(m+1, 0));
    for(const vector<int>& vec : skill)
    {
        int type = vec[0];
        int r1 = vec[1], c1 = vec[2];
        int r2 = vec[3], c2 = vec[4];
        int degree = vec[5];
        
        cumSum[r1][c1] += (type == 2) ? degree : -degree;
        cumSum[r1][c2+1] += (type == 2) ? -degree : degree;
        cumSum[r2+1][c1] += (type == 2) ? -degree : degree;
        cumSum[r2+1][c2+1] += (type == 2) ? degree : -degree;        
    }
    
    for(int i=0; i<n; ++i)
    {
        for(int j=1; j<m; ++j)
        {
            cumSum[i][j] += cumSum[i][j-1];
        }
    }
    for(int j=0; j<m; ++j)
    {
        for(int i=1; i<n; ++i)
        {
            cumSum[i][j] += cumSum[i-1][j];
        }
    }
    
    int answer = 0;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            board[i][j] += cumSum[i][j];
            if(board[i][j] > 0)
            {
                answer++;
            }
        }
    }    
    return answer;
}