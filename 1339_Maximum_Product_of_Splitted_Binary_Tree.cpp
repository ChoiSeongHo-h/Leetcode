/*
https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
-> Accepted (Medium)
*/

class Solution 
{
public:
    int maxProduct(TreeNode* root) 
    {
        int idx = -1;
        stack<pair<TreeNode*, int>> s;
        s.emplace(make_pair(root, -1));
        vector<int> feature;
        vector<long long> acc;
        vector<int> parents;
        while(!s.empty())
        {
            auto node = s.top().first;
            int parent = s.top().second;
            s.pop();
            
            ++idx;
            feature.resize(idx+1);
            parents.emplace_back(parent);
            acc.emplace_back(node->val);
            if(node->right != nullptr)
            {
                s.emplace(make_pair(node->right, idx));
                feature[idx] += 1;
            }
            if(node->left != nullptr)
            {
                s.emplace(make_pair(node->left, idx));
                feature[idx] += 2;
            }
        }
      
        vector<deque<int>> childs(parents.size());
        for(int i = 0; i<childs.size(); i++)
        {
            int parent = parents[i];
            if(parent != -1)
                childs[parent].emplace_back(i);
        }
      
        idx = 0;
        while(true)
        {
            if(feature[idx] >= 2)
            {
                feature[idx] -= 2;
                idx = childs[idx].front();
                continue;
            }
            if(feature[idx] >= 1)
            {
                feature[idx] -= 1;
                idx = childs[idx].back();
                continue;
            }
            if(feature[idx] == 0)
            {
                int parent = parents[idx];
                if(parent == -1)
                    break;
                acc[parent] += acc[idx];
                idx = parent;
                continue;
            }
        }
      
        long long maxSum = *max_element(acc.begin(), acc.end());
        long long ans = -1;
        for(auto i : acc)
            ans = max(ans, (maxSum-i)*i);

        return int(ans%(long long)(1000000007));
    }
};
