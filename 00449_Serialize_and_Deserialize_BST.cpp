"""
https://leetcode.com/problems/serialize-and-deserialize-bst/
-> Accepted (Medium)
"""
  
class Codec 
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string output;
        if(root == nullptr)
            return output;
      
        queue<pair<TreeNode*, TreeNode*>> q;
        q.emplace(make_pair(nullptr, root));
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            char append0 = 0;
            char append1 = 0;
            if(node.first != nullptr)
            {
                append0 = node.first->val/255;
                append1 = node.first->val%255;
            }
            char append2 = node.second->val/255;
            char append3 = node.second->val%255;
            output += append0;
            output += append1;
            output += append2;
            output += append3;
            if(node.second->left != nullptr)
                q.emplace(make_pair(node.second, node.second->left));
            if(node.second->right != nullptr)
                q.emplace(make_pair(node.second, node.second->right));
        }
        
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        TreeNode* output;
        if(data == "")
            return output;
        
        int len = data.length();
        int partial = 0;
        vector<int> nums;
        vector<int> parents;
        for(int i = 0; i<len; i += 4)
        {
            parents.emplace_back(data[i]*255 + (unsigned char)data[i+1]);
            nums.emplace_back(data[i+2]*255 + (unsigned char)data[i+3]);
        }

        int pt = 0;
        int sz = nums.size();
        queue<TreeNode*> q;
        output = new TreeNode();
        output->val = nums[pt];
        q.emplace(output);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            if(pt+1 != sz && parents[pt+1] == node->val && nums[pt+1] < node->val)
            {
                node->left = new TreeNode();
                ++pt;
                node->left->val = nums[pt];
                q.emplace(node->left);
            }
            if(pt+1 != sz && parents[pt+1] == node->val && node->val < nums[pt+1])
            {
                node->right = new TreeNode();
                ++pt;
                node->right->val = nums[pt];
                q.emplace(node->right);
            }
        }
        
        return output;
    }
};
