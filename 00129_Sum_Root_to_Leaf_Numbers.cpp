/*
https://leetcode.com/problems/sum-root-to-leaf-numbers/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int sumNumbers(TreeNode* root) 
    {
        uint32_t ans = 0;
        stack<pair<TreeNode*, TreeNode*>> s;
        vector<TreeNode*> path;
        s.emplace(make_pair(root, nullptr));
        while(!s.empty())
        {
            auto node = s.top();
            s.pop();

            while(node.second != nullptr && path.size() != 0 && path.back() != node.second)
            {
                path.pop_back();
            }
            path.emplace_back(node.first);

            if(node.first->left != nullptr)
                s.emplace(make_pair(node.first->left, node.first));
            if(node.first->right != nullptr)
                s.emplace(make_pair(node.first->right, node.first));
            
            if(node.first->left == nullptr && node.first->right == nullptr)
            {
                uint32_t padding = 1;
                for(int i = path.size()-1; i>=0; --i)
                {
                    ans += padding*uint32_t(path[i]->val);
                    padding *= 10;
                }
            }
        }

        return int(ans);
    }
};
