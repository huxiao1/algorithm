/*
题目描述
有一个n*m的棋盘(1<n,m<=400)，在某个点上有一个马,要求你计算出马到达棋盘上任意一个点最少要走几步

输入格式
一行四个数据，棋盘的大小和马的坐标
输出格式
一个n*m的矩阵，代表马到达某个点最少要走几步（左对齐，宽5格，不能到达则输出-1）

输入输出样例
输入 
3 3 1 1
输出
0    3    2    
3    -1   1    
2    1    4    
*/
#include <iostream>
#include <queue>
using namespace std;

#define N 405
int dir[8][2] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};  //马一次之后可到达的坐标
int a[N][N];
bool vis[N][N];
int n,m,sx,sy;

struct node
{
    int x;
    int y;
};

bool inmap(int x,int y)
{
    return x>=1 && x<=n && y>=1 && y<=m;
}

void bfs(int x,int y)
{
    vis[x][y] = 1;
    queue<node> q;
    q.push({x,y});
    a[x][y] = 0;

    while (!q.empty())
    {
        node now = q.front();
        for (int i = 0; i < 8; i++)
        {
            int nx = now.x + dir[i][0];
            int ny = now.y + dir[i][1];
            if (inmap(nx,ny) && vis[nx][ny] == 0)
            {
                vis[nx][ny] = 1;
                a[nx][ny] = a[now.x][now.y] + 1;  //上一步的步长加一
                q.push({nx,ny});
            }
        }
        q.pop();
    }
    
}


int main()
{
    cin>>n>>m>>sx>>sy;  //输入棋盘的大小和起点坐标
    for (int i = 1; i <= n; i++)  //设定都是从一开始
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = -1;
        }

    bfs(sx,sy);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%-5d",a[i][j]);
        }
        cout<<endl;
    }
    return 0;
}