"""
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
-> Accepted (Medium)
"""

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        int remains = 2;
        stack<array<TreeNode*, 2>> s;
        s.emplace(array<TreeNode*, 2>{root, nullptr});
        vector<vector<TreeNode*>> paths(2);
        while(!s.empty())
        {
            auto node = s.top()[0];
            auto parent = s.top()[1];
            s.pop();

            while(!paths[0].empty() && paths[0].back() != parent)
                paths[0].pop_back();
            paths[0].emplace_back(node);
            if(remains == 2)
            {
                while(!paths[1].empty() && paths[1].back() != parent)
                    paths[1].pop_back();
                paths[1].emplace_back(node);
            }
            
            if(node == p || node == q)
            {
                --remains;
                if(remains == 0)
                    break;
            }

            if(node->left != nullptr)
                s.emplace(array<TreeNode*, 2>{node->left, node});
            if(node->right != nullptr)
                s.emplace(array<TreeNode*, 2>{node->right, node});
        }

        TreeNode* ans = nullptr;
        int min_sz = min(paths[0].size(), paths[1].size());
        for(int i = 0; i<min_sz; ++i)
        {
            if(paths[0][i]->val == paths[1][i]->val)
                ans = paths[0][i];
            else
                break;
        }

        return ans;
    }
};
