"""
https://leetcode.com/problems/delete-nodes-and-return-forest/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        vector<int> d(1001, 0);
        for(int i = 0; i<to_delete.size(); ++i)
            d[to_delete[i]] = 1;

        vector<TreeNode*> ans;
        if(d[root->val] == 0)
            ans.emplace_back(root);

        queue<pair<TreeNode*, TreeNode*>> q;
        q.emplace(make_pair(nullptr, root));
        while(!q.empty())
        {
            auto parent = q.front().first;
            auto now = q.front().second;
            q.pop();

            if(parent != nullptr && d[parent->val] == 1)
            {
                if(parent->left != nullptr && parent->left == now)
                    parent->left = nullptr;
                else if(parent->right != nullptr && parent->right == now)
                    parent->right = nullptr;
                if(d[now->val] == 0)
                  ans.emplace_back(now);
            }

            if(now->left != nullptr)
            {
                q.emplace(make_pair(now, now->left));
                if(d[now->left->val] == 1)
                    now->left = nullptr;
            }
            if(now->right != nullptr)
            {
                q.emplace(make_pair(now, now->right));
                if(d[now->right->val] == 1)
                    now->right = nullptr;
            }
        }
      
        return ans;
    }
};
