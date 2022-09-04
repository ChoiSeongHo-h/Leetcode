/*
https://leetcode.com/problems/validate-binary-search-tree/
-> Accepted (Medium)
*/

class Solution
{
public:
    struct element
    {
        TreeNode* node;
        bool hasUpperBound;
        int upperBound;
        bool hasLowerBound;
        int lowerBound;
    };
    
    bool isValidBST(TreeNode* root)
    {
        stack<element> nodeQ;
        nodeQ.emplace(element{root, false, 0, false, 0});
        while(!nodeQ.empty())
        {
            auto node = nodeQ.top().node;
            bool hasUpperBound = nodeQ.top().hasUpperBound;
            int upperBound = nodeQ.top().upperBound;
            bool hasLowerBound = nodeQ.top().hasLowerBound;
            int lowerBound = nodeQ.top().lowerBound;
            nodeQ.pop();
            
            auto next = node->left;
            if(next != nullptr)
            {
                if(next->val >= node->val)
                    return false;
                if(hasLowerBound && lowerBound >= next->val)
                    return false;
                
                nodeQ.emplace(element{next, true, node->val, hasLowerBound, lowerBound});
            }
            next = node->right;
            if(next != nullptr)
            {
                if(node->val >= next->val)
                    return false;
                if(hasUpperBound && next->val >= upperBound)
                    return false;
                
                nodeQ.emplace(element{next, hasUpperBound, upperBound, true, node->val});
            }
        }
        
        return true;
    }
};
