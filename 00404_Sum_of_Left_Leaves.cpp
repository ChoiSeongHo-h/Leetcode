"""
https://leetcode.com/problems/sum-of-left-leaves/
-> Accepted (Easy)
"""
  
class Solution 
{
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.emplace(make_pair(root, 0));
        while(!q.empty())
        {
            auto node = q.front().first;
            int is_left = q.front().second;
            q.pop();

            if(is_left == 1 && node->left == nullptr && node->right == nullptr)
            {
                ans += node->val;
                continue;
            }
            
            if(node->left != nullptr)
                q.emplace(make_pair(node->left, 1));
            if(node->right != nullptr)
                q.emplace(make_pair(node->right, 0));
        }   

        return ans;
    }
};
