"""
https://leetcode.com/problems/swap-nodes-in-pairs/
-> Accepted (Medium)
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None :
            return None
        if head.next is None :
            return head

        refLink = head
        output = refLink

        while True :
            l0 = refLink
            if l0.next is None :
                break
            l1 = l0.next
            templ0Val = l0.val
            templ1Val = l1.val
            l0.val = templ1Val
            l1.val = templ0Val
            if l1.next is None :
                break
            refLink = l1.next

        return output
