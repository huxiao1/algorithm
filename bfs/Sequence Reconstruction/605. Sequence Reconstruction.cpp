#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<set>

/*
Input:org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
[1,2],[1,3],[2,3]
Output:true
*/

using namespace std;

class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        // write your code here
        map<int,set<int>> graph;
        map<int,int> indegree;
        queue<int> q;

        if (org.empty())
        {
            if (seqs.empty())
            {
                return true;
            }
            if ((seqs.size()==1) && (seqs[0].empty()))
            {
                return true;
            }
        }

        if (org.empty() || seqs.empty() || seqs[0].empty())
        {
            return false;
        }
        
        for (auto a:seqs)
        {
            if (a.size() == 1)
            {
                if (graph.find(a[0])==graph.end())
                {
                    graph[a[0]].insert(0);
                    if (indegree.find(a[0]) != indegree.end())
                    {
                        indegree[a[0]]++;
                    }
                    else
                    {
                        indegree[a[0]]=0;
                    }
                }
                continue;
            }
            
            for (int i = 0; i < a.size()-1; i++)        //[1,2,3] -> {{1:2},{2:3}}
            { 
                if (graph[a[i]].find(a[i+1]) == graph[a[i]].end())
                {
                    graph[a[i]].insert(a[i+1]);
                    if (indegree.find(a[i+1]) != indegree.end())
                    {
                        indegree[a[i+1]]++;
                    }
                    else
                    {
                        indegree[a[i+1]]=1;
                    }
                }
            }
        }


        for (int i=1; i<=org.size(); ++i) {   //所有的课都在org里面
            if (indegree[i]==0) {
                q.push(i);
            }
        }

        int index=0;            //org的前一个元素找完，下一个元素的度必定是0
        while(q.size()==1) {
            int n=q.front();
            q.pop();

            if (n!=org[index++]) 
                return false;
            
            for (auto i : graph[n]) {
                indegree[i]--;
                if (indegree[i]==0) {
                    q.push(i);
                }
            }
        }
        cout<<index;
        return index==org.size();
    }
};

int main()
{
    Solution SO;
    vector<int> org = {1};
    vector<vector<int>> seqs = {{1}};
    bool a = SO.sequenceReconstruction(org,seqs);
    cout<<a<<endl;
    return 0;
}