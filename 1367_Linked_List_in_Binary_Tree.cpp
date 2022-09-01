/*
https://leetcode.com/problems/linked-list-in-binary-tree/
-> Accepted (Medium)
*/

class Solution 
{
public:
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        vector<int> headVec;
        while(1)
        {
            headVec.emplace_back(head->val);
            if(head->next == nullptr)
                break;
            
            head = head->next;
        }
        const int listSz = headVec.size();
        
        vector<int> path;
        stack<pair<TreeNode*, int>> pNodeDepthStack;
        pNodeDepthStack.emplace(make_pair(root, 1));
        while(!pNodeDepthStack.empty())
        {
            auto pNode = pNodeDepthStack.top().first;
            int depth = pNodeDepthStack.top().second;
            pNodeDepthStack.pop();
            
            while(path.size() >= depth)
                path.pop_back();
            path.emplace_back(pNode->val);
            
            bool isDeadlock = true;
            auto pNext = pNode->left;
            if(pNext != nullptr)
            {
                pNodeDepthStack.emplace(make_pair(pNext, depth+1));   
                isDeadlock = false;
            }         
            pNext = pNode->right;
            if(pNext != nullptr)
            {
                pNodeDepthStack.emplace(make_pair(pNext, depth+1));   
                isDeadlock = false;
            }
            
            if(isDeadlock)
            {
                if(path.size() >= listSz)
                {
                    auto it = search(path.begin(), path.end(), headVec.begin(), headVec.end());
                    if (it != path.end())
                        return true;
                }
            }
                
        }
        
        
        return false;
        
    }
};
