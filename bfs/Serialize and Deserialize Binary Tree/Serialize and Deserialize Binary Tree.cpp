#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
#include<sstream>

using namespace std;

//Definition of TreeNode:
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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    vector<string> split(const string &str, string delim)
    {
        vector<string> results;
        int lastIndex = 0;
        int index;

        while ((index = str.find(delim,lastIndex))!=string::npos)
        {
            results.push_back(str.substr(lastIndex,index - lastIndex));
            lastIndex = index + delim.length();
        }

        if (lastIndex != str.length())
        {
            results.push_back(str.substr(lastIndex,str.length() - lastIndex));
        }
        return results;
    }

    string serialize(TreeNode * root) {
        // write your code here
        if (root == NULL)
        {
            return "{}";
        }
        string res;
        res = res + "{";
        res = res + to_string(root->val);
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp != NULL)
            {
                res = res + "," + to_string(temp->val);
                q.push(temp->left);
                q.push(temp->right);
            }
            else
            {
                res = res + "," + "#";
            }
        }

        int size = res.size();
        int id = size -1;
        while (id>0 && (res[id]=='#' || res[id]==','))
        {
            id--;
        }
        res.resize(id+1);
        res = res + "}";
        return res;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        // write your code here
        if(data == "{}")
        {
            return NULL;
        }
        vector<string> vals;
        vals = split(data.substr(1,data.size() - 2),",");
        
        TreeNode *root = new TreeNode(atoi(vals[0].c_str()));
        queue<TreeNode *> q;
        q.push(root);

        bool left = true;

        for (int i = 1; i < vals.size(); i++)
        {
            if (vals[i] != "#")
            {
                TreeNode *node = new TreeNode(atoi(vals[i].c_str()));
                if(left)
                {
                    q.front()->left = node;
                }
                else
                {
                    q.front()->right = node;
                }
                q.push(node);
            }
            if (!left)
            {
                q.pop();
            }
            left = !left;   
        }
        return root;
    }
};