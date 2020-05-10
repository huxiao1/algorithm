#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    int islands = 0;
    struct node{
        int x;
        int y;
    };

    bool inmap(vector<vector<bool>> &grid,int x,int y)
    {
        return x >= 0 && x <= grid.size() -1 && y >= 0 && y <= grid[0].size() -1;
    }

    void bfs(vector<vector<bool>> &vis,vector<vector<bool>> &grid,int x,int y)
    {
        int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        queue<node> q;
        q.push({x,y});
        while (!q.empty())
        {
            node now = q.front();
            for (int i = 0; i < 4; i++)
            {
                int nx = now.x + dir[i][0];
                int ny = now.y + dir[i][1];
            
                if(inmap(grid,nx,ny))
                {
                    if (vis[nx][ny] == 1)
                    {
                        continue;
                    }
                    else
                    {
                        vis[nx][ny] = 1;
                        if (grid[nx][ny] == 1)
                        {
                            q.push({nx,ny});
                        }
                    }     
                }
            } 
            q.pop();
        }
    }

    int numIslands(vector<vector<bool>> &grid) {
        if (grid.size() == 0)
        {
            return 0;
        }
        
        int row = grid.size();
        int column = grid[0].size();
        
        vector<vector<bool>> vis(row);
        for(int i=0; i<vis.size() ;i++) {
            vis[i].resize(column);
        }

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (vis[i][j] == 1)
                {
                    continue;
                }
                else
                {
                    if (grid[i][j] == 1)
                    {
                        islands++;
                        vis[i][j] = 1;
                        bfs(vis,grid,i,j);
                    }
                }
            }
        return islands; 
    }
};

int main()
{
    Solution sol;
    vector<vector<bool>> grid(0);
    for(int i=0; i<grid.size() ;i++) {
        grid[i].resize(0);
    }
    
    int islands = sol.numIslands(grid);
    cout<<islands;
    return 0;
}