"""
https://leetcode.com/problems/count-complete-tree-nodes/
-> Accepted (Medium)
"""

class Solution 
{
public:
    int countNodes(TreeNode* root) 
    {
        if(root == nullptr)
            return 0;

        stack<TreeNode*> s;
        s.emplace(root);
        int h = -1;
        while(!s.empty())
        {
            auto node = s.top();
            s.pop();

            ++h;
            if(node->left != nullptr)
                s.emplace(node->left);
        }
        if(h == 0)
            return 1;

        int num_bottom = pow(2, h);
        int left = 1;
        int right = num_bottom;
        int can;
        while(left<=right)
        {
            int mid = (left+right)/2;
            int lower = 1;
            int upper = num_bottom;

            auto node = root;
            int ok = 1;
            for(int i = 0; i<h; ++i)
            {
                int dir = mid > (lower+upper)/2;
                if(dir == 0)
                {
                    if(node->left == nullptr)
                    {
                        ok = 0;
                        break;
                    }
                    
                    node = node->left;
                    upper = (lower+upper)/2;
                }
                else
                {
                    if(node->right == nullptr)
                    {
                        ok = 0;
                        break;
                    }
                    
                    node = node->right;
                    lower = (lower+upper)/2+1;
                }
            }
            if(ok == 1)
            {
                can = mid;
                if(left == right)
                    break;
                left = mid+1;
            }
            else
            {
                if(left == right)
                    break;
                right = mid;
            }
        }

        return num_bottom-1+can;
    }
};
