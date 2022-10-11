/*
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int pathSum(TreeNode* root, int targetSum) 
    {
        if(root == nullptr)
            return 0;
        vector<TreeNode*> path;
        stack<pair<TreeNode*, TreeNode*>> s;
        s.emplace(make_pair(nullptr, root));
        long long acc_sum = 0;
        int ans = 0;
        while(!s.empty())
        {
            auto parent = s.top().first;
            auto node = s.top().second;
            s.pop();
            
            while(!path.empty() && path.back() != parent)
            {
                acc_sum -= path.back()->val;
                path.pop_back();
            }
            path.emplace_back(node);
            acc_sum += node->val;
            
            long long temp_acc = acc_sum;
            for(auto& i : path)
            {
                if(temp_acc == (long long)targetSum)
                    ++ans;
                temp_acc -= (long long)(i->val);
            }

            if(node->right != nullptr)
                s.emplace(make_pair(node, node->right));
            if(node->left != nullptr)
                s.emplace(make_pair(node, node->left));
        }
        
        return ans;
    }
};
