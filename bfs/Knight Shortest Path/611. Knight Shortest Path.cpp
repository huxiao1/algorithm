#include<iostream>
#include<queue>
#include<vector>

using namespace std;


//  Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
    bool inbound(vector<vector<bool> > &grid,Point p)
    {
        return (p.x>=0 && p.x<grid.size() && p.y>=0 && p.y<grid[0].size()) && !grid[p.x][p.y];  //在矩阵范围内且不是障碍点
    }

    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        int row = grid.size();
        int column = grid[0].size();
        vector<vector<bool>> vis(row);
        for(int i=0; i<vis.size() ;i++) {
            vis[i].resize(column);
        }
        int dir[8][2] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
        queue<Point> q;
        q.push(source);
        vis[source.x][source.y] = 1;
        int steps = 0;

        while (!q.empty())
        {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++)
            {
                Point p = q.front();
                q.pop();

                if (p.x == destination.x && p.y == destination.y)
                {
                    return steps;
                }

                for (int i = 0; i < 8; i++)
                {
                    Point temp = Point(p.x+dir[i][0],p.y+dir[i][1]);
                    if (inbound(grid,temp) && vis[temp.x][temp.y] == 0)
                    {
                        q.push(temp);
                        vis[temp.x][temp.y] = 1;
                    }
                    
                }
            }
            steps++;
        }
        return -1;

    }
};