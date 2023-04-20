/*
https://leetcode.com/problems/remove-linked-list-elements/
-> Accepted (Easy)
*/

class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        while(head != nullptr && head->val == val)
            head = head->next;

        if(head == nullptr)
            return head;

        auto now = head;
        while(now->next != nullptr)
        {
            auto next = now->next;
            if(next->val == val)
                now->next = next->next;
            else
                now = now->next;
        }

        return head;
    }
};
