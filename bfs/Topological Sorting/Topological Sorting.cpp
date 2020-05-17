#include<iostream>
#include<map>
#include<vector>
#include<queue>

using namespace std;

//  Definition for Directed graph.
struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
 };
 

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        map<DirectedGraphNode*,int> map;
        vector<DirectedGraphNode*> res;
        queue<DirectedGraphNode*> queue;

        //把除了头节点外的节点放入map
        for (auto i:graph)
        {
            for (auto j:i->neighbors)
            {
                if (map.find(j) == map.end())
                {
                    map[j] = 1;
                }
                else
                {
                    map[j] += 1;
                }
            }
        }
        //找到头节点并放入队列和res数组
        for (auto i:graph)
        {
            if (map.find(i) == map.end())
            {
                queue.push(i);
                res.push_back(i);
            }
        }

        while (!queue.empty())
        {
            DirectedGraphNode *temp = queue.front();
            queue.pop();
            for (auto i:temp->neighbors)
            {
                map[i] -= 1;
                if (map[i] == 0)
                {
                    queue.push(i);
                    res.push_back(i);
                }   
            }
        }
        return res;
    }
};