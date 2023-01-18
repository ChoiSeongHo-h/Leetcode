"""
https://leetcode.com/problems/merge-k-sorted-lists/
-> Accepted (Hard)
"""
  
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int sz = lists.size();
        if(lists.size() == 0)
            return nullptr;
      
        ListNode*  ans = new ListNode();
        ans->val = 1000000;
        map<int, vector<ListNode*>> head_pts_map;
        for(int i = 0; i<sz; ++i)
        {
            if(lists[i] == nullptr)
                continue;
            
            int head = lists[i]->val;
            if(head_pts_map.find(head) == head_pts_map.end())
                head_pts_map.emplace(head, vector<ListNode*>{lists[i]});
            else
                head_pts_map[head].emplace_back(lists[i]);
        }

        ListNode* tail = ans;
        ListNode* before = ans;
        while(!head_pts_map.empty())
        {
            auto it = head_pts_map.begin();
            int head = it->first;
            vector<ListNode*>& vec = it->second;
            while(vec.size() != 0)
            {
                tail->val = head;
                tail->next = new ListNode();
                before = tail;
                tail = tail->next;

                auto& pt = vec[vec.size()-1];
                if(pt->next == nullptr)
                {
                    vec.pop_back();
                    continue;
                }

                pt = pt->next;
                int next_head = pt->val;
                if(next_head == head)
                    continue;

                if(head_pts_map.find(next_head) == head_pts_map.end())
                    head_pts_map.emplace(next_head, vector<ListNode*>{pt});
                else
                    head_pts_map[next_head].emplace_back(pt);

                vec.pop_back();
            }
            head_pts_map.erase(it);
        }
        if(before->next != nullptr)
            before->next = nullptr;
        if(ans->val == 1000000)
            return nullptr;
            
        return ans;
    }
};
