#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int dir[8][2] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};  //马一次之后可到达的坐标
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty())
    {
        int first = q.front();
        cout<<first<< " ";
        q.pop();
    }
    return 0;
    
}