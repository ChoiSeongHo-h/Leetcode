"""
https://leetcode.com/problems/maximum-width-of-binary-tree/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*, uint64_t>> q;
        q.emplace(make_pair(root, 1));
        uint64_t ans = 0;
        while(!q.empty())
        {
            int sz = q.size();
            uint64_t first = -1;
            uint64_t offset = -1;
            uint64_t last = -1;
            while(sz--)
            {
                auto node = q.front().first;
                uint64_t idx = q.front().second;
                q.pop();

                if(first == -1)
                    first = idx;
                if(sz == 0)
                    last = idx;
                if(offset == -1)
                {
                    if(node->left != nullptr)
                        offset = idx*2-1-1;
                    else if(node->right != nullptr)
                        offset = idx*2-1;
                }
                if(node->left != nullptr)
                    q.emplace(make_pair(node->left, idx*2-1-offset));
                if(node->right != nullptr)
                    q.emplace(make_pair(node->right, idx*2-offset));
            }
            ans = max(ans, last+1-first);
        }

        return (int)ans;   
    }
};
