#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class TreeNode {
  public:
      int val;
      TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> one;
            for (int i = 0; i < size; i++)
            {
                TreeNode *top = q.front();
                one.push_back(top->val);
                q.pop();
                if (top->left != NULL)
                {
                    q.push(top->left);
                }
                if (top->right != NULL)
                {
                    q.push(top->right);
                }
            }
            res.push_back(one);
        }
        return res;
    }
};

int main()
{
    TreeNode *root;
    root->val = 1;
    root->left->val = 2;
    root->right->val = 3;
    Solution sol;
    vector<vector<int>> res;
    res = sol.levelOrder(root);
    return 0;
}