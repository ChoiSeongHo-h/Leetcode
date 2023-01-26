"""
https://leetcode.com/problems/binary-tree-maximum-path-sum/
-> Accepted (Hard)
"""

class Solution 
{
public:
    int ans = -100000;

    int get_acc(TreeNode* node)
    {
        if(node->left == nullptr && node->right == nullptr)
        {
            ans = max(ans, node->val);
            return node->val;
        }
        
        int left_acc = 0;
        if(node->left != nullptr)
            left_acc = max(0, get_acc(node->left));
        int right_acc = 0;
        if(node->right != nullptr)
            right_acc = max(0, get_acc(node->right));

        int local_max = node->val + left_acc + right_acc;
        ans = max(ans, local_max);
        return node->val + max(left_acc, right_acc);
    }

    int maxPathSum(TreeNode* root) 
    {
        get_acc(root);
        return ans;
    }
};
