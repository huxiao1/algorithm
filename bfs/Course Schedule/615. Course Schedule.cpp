#include<iostream>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // write your code here
        vector<unordered_set<int> > graph(numCourses);
        vector<int> indegree(numCourses);
        queue<int> q;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i].second].insert(prerequisites[i].first);
        }
    
        for (int i = 0; i < numCourses; i++)
        {
            for (auto it=graph[i].begin(); it != graph[i].end(); it++)
            {
                ++indegree[*it];   //看看先修课有几门后修课
            }
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            numCourses--;
            for (auto it = graph[temp].begin(); it !=graph[temp].end(); it++)
            {
                if(--indegree[*it]  == 0)
                {
                    q.push(*it);
                }
            }
        }
        if (numCourses==0)
        {
            return true;
        }
        else
        {
            return false;
        } 
    }
};