"""
https://leetcode.com/problems/linked-list-cycle-ii/
-> Accepted (Medium)
"""
  
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == nullptr)
            return nullptr;
      
        ListNode* rabbit = head;
        ListNode* turtle = head;
        while(1)
        {
            if(turtle->next != nullptr)
                turtle = turtle->next;
          
            if(rabbit->next != nullptr && rabbit->next->next != nullptr)
                rabbit = rabbit->next->next;
            else
                return nullptr;
            
            if(turtle == rabbit)
                break;
        }
      
        rabbit = head;
        while(1)
        {
            if(turtle == rabbit)
                break;
          
            turtle = turtle->next;
            rabbit = rabbit->next;
        }

        return rabbit;
    }
};
