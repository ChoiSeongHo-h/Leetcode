/*
https://leetcode.com/problems/binary-search-tree-iterator/
-> Accepted (Medium)
*/

class BSTIterator 
{
public:
    vector<TreeNode*> temp;
    int idx = 0;

    void traverse(TreeNode* node)
    {
        if(node->left != nullptr)
            traverse(node->left);
      
        temp.emplace_back(node);
      
        if(node->right != nullptr)
            traverse(node->right);
    }

    BSTIterator(TreeNode* root)
    {
        traverse(root);
    }
    
    int next() 
    {
        int val = temp[idx]->val;
        ++idx;
        return val;
    }
    
    bool hasNext() 
    {
        if(idx == temp.size())
            return 0;
        else
            return 1;
    }
};
