/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
-> Accepted (Medium)
*/

class Solution 
{
public:
    Node* connect(Node* root) 
    {
        if(root == nullptr)
            return root;
        
        queue<Node*> q;
        q.emplace(root);
        Node* before = nullptr;
        bool is_first;
        while(!q.empty())
        {
            int sz = q.size();
            is_first = true;
            while(sz--)
            {
                auto node = q.front();
                q.pop();

                if(!is_first)
                    before->next = node;
                if(node->left != nullptr)
                    q.emplace(node->left);
                if(node->right != nullptr)
                    q.emplace(node->right);           
                
                before = node;
                is_first = false;
            }
        }
        
        return root;
    }
};
