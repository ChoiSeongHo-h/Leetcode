/*
https://leetcode.com/problems/balanced-binary-tree/
-> Accepted (Easy)
*/

class Solution 
{
public:
    bool balanced = true;

    int traverse(TreeNode* node)
    {
        if(node == nullptr)
            return 0;
        
        int left = traverse(node->left);
        int right = traverse(node->right);
        balanced *= (abs(left-right) <= 1);
        return max(left, right)+1;
    }

    bool isBalanced(TreeNode* root) 
    {
        traverse(root);
        return balanced;
    }
};
