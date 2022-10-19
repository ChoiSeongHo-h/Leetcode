"""
https://leetcode.com/problems/odd-even-linked-list/
-> Accepted (Medium)
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None :
            return None
        if head.next is None :
            return head

        headOdd = head
        headEven = head.next
        tailOdd = headOdd
        tailEven = headEven

        while True :
            if tailEven.next is None :
                break
            tempOdd = tailEven.next
            tailOdd.next = tempOdd
            tailOdd = tempOdd

            if tempOdd.next is None :
                tailEven.next = None
                break
            tempEven = tempOdd.next
            tailEven.next = tempEven
            tailEven = tempEven

        tailOdd.next = headEven
        return headOdd
