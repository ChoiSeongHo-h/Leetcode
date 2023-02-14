"""
https://leetcode.com/problems/deepest-leaves-sum/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    int deepestLeavesSum(TreeNode* root) 
    {
        int max_depth = 0;
        vector<int> leaves;
        vector<int> depths;
      
        queue<TreeNode*> q;
        q.emplace(root);
        int depth = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto node = q.front();
                q.pop();
                if(node->left == nullptr && node->right == nullptr)
                {
                    leaves.emplace_back(node->val);
                    depths.emplace_back(depth);
                    continue;
                }

                if(node->left != nullptr)
                    q.emplace(node->left);
                if(node->right != nullptr)
                    q.emplace(node->right);
            }
            max_depth = max(max_depth, depth);
            ++depth;
        }
        
        int sz = leaves.size();
        int ans = 0;
        for(int i = 0; i<sz; ++i)
        {
            if(depths[i] != max_depth)
                continue;

            ans += leaves[i];
        }

        return ans;
    }
};
