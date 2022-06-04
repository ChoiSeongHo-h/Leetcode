"""
https://github.com/TAVE-7-python-algorithm-study/algorithm-interview
-> 19 역순 연결 리스트 II (★★/★★★)

https://leetcode.com/problems/reverse-linked-list-ii/
-> Accepted
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if head.next is None:
            return head
        if left == right:
            return head

        refNode = head
        idx = 1
        lNode = None
        rNode = None
        numList = []
        #get left node, num list, right node
        while True:
            if rNode is not None:
                break
            if idx == left:
                lNode = refNode
                numList.append(refNode.val)
                while True:
                    if idx == right:
                        rNode = refNode
                        break
                    idx = idx + 1
                    refNode = refNode.next
                    numList.append(refNode.val)
            idx = idx + 1
            refNode = refNode.next

        #reverse
        numList.reverse()

        #change
        idx = 0
        while lNode is not rNode:
            lNode.val = numList[idx]
            lNode = lNode.next
            idx = idx + 1
        lNode.val = numList[idx]

        return head