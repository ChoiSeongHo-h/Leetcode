"""
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
-> Accepted (Medium)
"""

class Solution 
{
public:
    Node* connect(Node* root) 
    {
        if(root == nullptr)
            return root;

        queue<Node*> q;
        q.emplace(root);
        while(!q.empty())
        {
            int sz = q.size();
            queue<Node*> q_temp;

            while(sz--)
            {
                auto node = q.front();
                q.pop();

                q_temp.emplace(node);
                if(node->left != nullptr)
                    q.emplace(node->left);
                if(node->right != nullptr)
                    q.emplace(node->right);
            }
            while(!q_temp.empty())
            {
                auto node = q_temp.front();
                q_temp.pop();

                if(q_temp.size() == 0)
                    node->next = nullptr;
                else
                    node->next = q_temp.front();
            }
        }
        
        return root;
    }
};
