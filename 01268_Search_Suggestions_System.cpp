/*
https://leetcode.com/problems/search-suggestions-system/
-> Accepted (Medium)
*/

// trie
class Solution 
{
public:
    int a = 'a';

    struct Node
    {
        Node()
        {
            next = vector<Node*>(26, nullptr);
            is_end = false;
        }
        vector<Node*> next;
        string word;
        bool is_end;
    };

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        Node* root = new Node();
        for(int i = 0; i<products.size(); ++i)
        {
            auto &word = products[i];
            auto node = root;
            for(int j = 0; j<word.length(); ++j)
            {
                int target = word[j]-a;
                if(node->next[target] == nullptr)
                    node->next[target] = new Node();
              
                node = node->next[target];
                if(node->word != "")
                    continue;
              
                for(int k = 0; k<=j; ++k)
                    node->word += word[k];
            }
          
            node->is_end = true;
        }

        vector<vector<string>> ans;
        auto node = root;
        for(int i = 0; i<searchWord.length(); ++i)
        {
            int target = searchWord[i]-a;
            vector<string> suggestion;
            if(node->next[target] == nullptr)
            {
                ans.emplace_back(suggestion);
                break;
            }
            node = node->next[target];
            stack<Node*> s;
            s.emplace(node);
            while(!s.empty())
            {
                auto now = s.top();
                s.pop();

                if(now->is_end)
                {
                    suggestion.emplace_back(now->word);
                    if(suggestion.size() == 3)
                        break;
                }
                for(int i = 25; i>=0; --i)
                {
                    if(now->next[i] == nullptr)
                        continue;

                    s.emplace(now->next[i]);
                }
            }
            ans.emplace_back(suggestion);
        }
        while(ans.size() != searchWord.size())
            ans.emplace_back(vector<string>());

        return ans;
    }
};


// binary search
class Solution 
{
public:
    vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
        auto it = A.begin();
        sort(A.begin(), A.end());
        vector<vector<string>> res;
        string cur = "";
        for (char c : searchWord) {
            cur += c;
            vector<string> suggested;
            it = lower_bound(it, A.end(), cur);
            for (int i = 0; i < 3 && it + i != A.end(); i++) {
                string& s = *(it + i);
                if (s.find(cur) != 0)
                    break;
                    
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }
};
