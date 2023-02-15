"""
https://leetcode.com/problems/longest-palindromic-substring/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    bool has_1(TreeNode* node)
    {
        if(node->left == nullptr && node->right == nullptr)
        {
            if(node->val == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool left_has_1 = false;
        bool right_has_1 = false;

        if(node->left != nullptr)
        {
            left_has_1 = has_1(node->left);
            if(left_has_1 == false)
                node->left = nullptr;
        }
        if(node->right != nullptr)
        {
            right_has_1 = has_1(node->right);
            if(right_has_1 == false)
                node->right = nullptr;
        }

        return left_has_1 + right_has_1 + (node->val == 1);
    }

    TreeNode* pruneTree(TreeNode* root) 
    {
        bool root_has_1 = has_1(root);
        if(root_has_1 == false)
            return nullptr;
        return root;
    }
};
