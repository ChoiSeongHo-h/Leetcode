/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
            
        q.emplace(root);
        int depth = 0;
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> candidates;
            while(sz--)
            {
                auto node = q.front();
                q.pop();

                candidates.emplace_back(node->val);
                if(node->left != nullptr)
                    q.emplace(node->left);
                if(node->right != nullptr)
                    q.emplace(node->right);
            }
            if(depth % 2 == 1)
                reverse(candidates.begin(), candidates.end());
            ans.emplace_back(candidates);
            ++depth;
        }      

        return ans;
    }
};
