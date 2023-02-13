"""
https://leetcode.com/problems/implement-trie-prefix-tree/
-> Accepted (Medium)
"""
  
class Trie 
{
public:
    struct Node
    {
        vector<Node*> data;
        bool is_end;
        Node()
        {
            data = vector<Node*>(26, nullptr);
            is_end = false;
        }
    };
    
    Node* head;
    int a = 'a';

    Trie() 
    {
        head = new Node();
    }
    
    void insert(string word) 
    {
        int len = word.length();
        auto now = head;
        for(int i = 0; i<len; ++i)
        {
            int idx = word[i]-a;
            if(now->data[idx] == nullptr)
                now->data[idx] = new Node();
          
            now = now->data[idx];
        }
      
        now->is_end = true;
    }
    
    bool search(string word) 
    {
        int len = word.length();
        auto now = head;
        for(int i = 0; i<len; ++i)
        {
            int idx = word[i]-a;
            if(now->data[idx] == nullptr)
                return false;
          
            now = now->data[idx];
        }
      
        if(!now->is_end)
            return false;
        
        return true;
    }
    
    bool startsWith(string prefix) 
    {
        int len = prefix.length();
        auto now = head;
        for(int i = 0; i<len; ++i)
        {
            int idx = prefix[i]-a;
            if(now->data[idx] == nullptr)
                return false;
          
            now = now->data[idx];
        }
        
        return true;
    }
};
