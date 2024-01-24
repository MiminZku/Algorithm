#include <iostream>

using namespace std;

int mat[50][50];

int dy[] = {0,0,-1,1,-1,-1,1,1};
int dx[] = {-1,1,0,0,-1,1,-1,1};

int w,h;

void Paint(int y, int x, int num)
{
    mat[y][x] = num;
    for(int i=0; i<8; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || nx < 0 || ny >= h || nx >= w)  continue;
        if(mat[ny][nx] >= 0)    continue;
        Paint(ny, nx, num);
    }
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    while(true)
    {
        cin>>w>>h;
        if(w==0)    break;

        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                cin>>mat[i][j];
                mat[i][j] *= -1;
            }
        }

        int num = 0;
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(mat[i][j] < 0)
                {
                    Paint(i, j, ++num);
                }
            }
        }
        cout<<num<<'\n';
    }
}