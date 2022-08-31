/*
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
-> Accepted (Medium)
*/

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        
        stack<vector<int>> invOrder;
        queue<TreeNode*> bfsQ;
        bfsQ.emplace(root);
        while(!bfsQ.empty())
        {
            int qSz = bfsQ.size();
            vector<int> depthWiseVec;
            while(qSz > 0)
            {
                qSz--;
                
                auto pNode = bfsQ.front();
                bfsQ.pop();

                depthWiseVec.emplace_back(pNode->val);
                    
                if(pNode->left != nullptr)
                    bfsQ.emplace(pNode->left);
                if(pNode->right != nullptr)
                    bfsQ.emplace(pNode->right);
            }
            invOrder.emplace(depthWiseVec);
        }
        
        while(!invOrder.empty())
        {
            ans.emplace_back(invOrder.top());
            invOrder.pop();
        }
            
        
        return ans;
    }
};
