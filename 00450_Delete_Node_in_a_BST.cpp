/*
https://leetcode.com/problems/delete-node-in-a-bst/
-> Accepted (Medium)
*/

class Solution 
{
public:
    void erase0(TreeNode* parent, TreeNode* target, TreeNode* &root)
    {
        if(target == root)
        {
            root = nullptr;
            return;
        }

        if(parent->left == target)
            parent->left = nullptr;
        else
            parent->right = nullptr;
    }

    void erase1(TreeNode* parent, TreeNode* target, TreeNode* &root) 
    {
        TreeNode* child = target->left;
        if(child == nullptr)
            child = target->right;

        if(target == root)
        {
            root = child;
            return;
        }

        if(parent->left == target)
            parent->left = child;
        else
            parent->right = child;
    }

    void erase2(TreeNode* parent, TreeNode* target, TreeNode* &parent_new, TreeNode* &target_new) 
    {
        target_new = target->right;
        parent_new = target;
        while(true)
        {
            if(target_new->left != nullptr)
            {
                parent_new = target_new;
                target_new = target_new->left;
            }
            else
                break;
        }

        target->val = target_new->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        TreeNode* now = root;
        TreeNode* target = nullptr;
        TreeNode* parent = nullptr;
        while(true)
        {
            if(now == nullptr)
                break;

            if(now->val == key)
            {
                target = now;
                break;
            }
            else if(now->val < key)
            {
                parent = now;
                now = now->right;
            }
            else
            {
                parent = now;
                now = now->left;
            }
        }

        if(target == nullptr)
            return root;

        int num_childs = 2;
        if(target->left == nullptr)
            --num_childs;
        if(target->right == nullptr)
            --num_childs;

        while(num_childs == 2)
        {
            TreeNode* parent_new = nullptr;
            TreeNode* target_new = nullptr;
            erase2(parent, target, parent_new, target_new);
            parent = parent_new;
            target = target_new;

            num_childs = 2;
            if(target->left == nullptr)
                --num_childs;
            if(target->right == nullptr)
                --num_childs;
        }
        
        if(num_childs == 0)
            erase0(parent, target, root);
        else if(num_childs == 1)
            erase1(parent, target, root);

        return root;
    }
};
