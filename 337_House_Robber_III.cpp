/*
https://leetcode.com/problems/house-robber-iii/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int use(TreeNode* node)
    {
        if(node == nullptr)
            return 0;
            
        if(using_map.find(node) == using_map.end())
        {
            int res = node->val + use_not(node->left) + use_not(node->right);
            using_map.emplace(node, res);
            return res;
        }

        return using_map[node];
    }

    int use_not(TreeNode* node)
    {
        if(node == nullptr)
            return 0;

        if(not_using_map.find(node) == not_using_map.end())
        {
            int res = max(use(node->left), use_not(node->left)) + max(use(node->right), use_not(node->right));
            not_using_map.emplace(node, res);
            return res;
        }

        return not_using_map[node];
    }

    unordered_map<TreeNode*, int> using_map;
    unordered_map<TreeNode*, int> not_using_map;
    
    int rob(TreeNode* root) 
    {
        int using_root = use(root);
        int not_using_root = use_not(root);
        return max(using_root, not_using_root);
    }
};
