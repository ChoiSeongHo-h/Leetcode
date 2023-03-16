/*
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
-> Accepted (Medium)
*/

class Solution 
{
public:
    vector<int> tb;
    int min_val;
    vector<int> *p_inorder;
    vector<int> *p_postorder;

    void find_ans(TreeNode* &node, int in_lower, int in_upper, int post_idx)
    {
        node->val = p_postorder->at(post_idx);
        if(in_upper - in_lower == 1)
            return;

        int in_idx = tb[node->val - min_val];

        int post_idx_next0 = post_idx - 1;
        int val_next0 = p_postorder->at(post_idx_next0);
        int in_idx_next0 = tb[val_next0 - min_val];
        if(in_idx < in_idx_next0 && in_idx_next0 < in_upper)
        {
            node->right = new TreeNode();
            find_ans(node->right, in_idx+1, in_upper, post_idx_next0);
        }
        
        if(post_idx < in_upper - in_idx)
            return;

        int post_idx_next1 = post_idx - (in_upper - in_idx);
        int val_next1 = p_postorder->at(post_idx_next1);
        int in_idx_next1 = tb[val_next1 - min_val];
        if(in_lower <= in_idx_next1 && in_idx_next1 < in_idx)
        {
            node->left = new TreeNode();
            find_ans(node->left, in_lower, in_idx, post_idx_next1);
        }
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        p_inorder = &inorder;
        p_postorder = &postorder;
        min_val = 10000;
        int max_val = -10000;
        for(int i = 0; i<inorder.size(); ++i)
        {
            min_val = min(min_val, inorder[i]);
            max_val = max(max_val, inorder[i]);
        }
        tb = vector<int>(max_val - min_val + 1, -1);
        for(int i = 0; i<inorder.size(); ++i)
            tb[inorder[i] - min_val] = i;

        TreeNode* root = new TreeNode();
        TreeNode* node = root;
        find_ans(node, 0, postorder.size(), postorder.size()-1);
        
        return root;
    }
};
