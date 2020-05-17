#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;
//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
 

class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (!node)
        {
            return NULL;
        }

        UndirectedGraphNode *p1 = node;
        UndirectedGraphNode *p2 = new UndirectedGraphNode(node->label);

        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> hashmap;
        hashmap[p1] = p2;
        queue<UndirectedGraphNode*> q;
        q.push(p1);

        while (!q.empty())
        {
            p1 = q.front();
            q.pop();
            p2 = hashmap[p1];

            for (int i = 0; i < p1->neighbors.size(); i++)
            {
                UndirectedGraphNode* pNode = p1->neighbors[i];
                if (hashmap.count(pNode)>0)
                {
                    p2->neighbors.push_back(hashmap[pNode]);
                }
                else
                {
                    UndirectedGraphNode *tempNode = new UndirectedGraphNode(pNode->label);
                    hashmap[pNode]=tempNode;
                    p2->neighbors.push_back(tempNode);
                    q.push(pNode);
                }
            }
        }
        return hashmap[node];
    }
};