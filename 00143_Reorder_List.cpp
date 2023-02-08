"""
https://leetcode.com/problems/reorder-list/
-> Accepted (Medium)
"""

class Solution 
{
public:
    void reorderList(ListNode* head) 
    {
        vector<ListNode*> s;
        queue<ListNode*> q;
        auto node = head;
        int cnt = 0;
        while(node != nullptr)
        {
            s.emplace_back(node);
            q.emplace(node);
            node = node->next;
            ++cnt;
        }

        if(cnt == 1)
            return;

        auto front = q.front();
        q.pop();
        
        auto top = s.back();
        s.pop_back();

        front->next = top;

        for(int i = 1; i<cnt/2; ++i)
        {
            front = q.front();
            q.pop();

            top->next = front;

            top = s.back();
            s.pop_back();

            front->next = top;
        }
        if(cnt%2 == 1)
        {
            top->next = q.front();
            top = top->next;
        }
        top->next = nullptr;
    }
};
