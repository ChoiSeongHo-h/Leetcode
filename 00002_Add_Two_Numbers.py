"""
https://leetcode.com/problems/add-two-numbers/
-> Accepted (Medium)
"""

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l1List = []
        l2List = []
        #for indexing
        l = [l1List, l2List]

        #linked list to list
        while l1.next is not None:
            l1List.append(l1.val)
            l1 = l1.next
        l1List.append(l1.val)

        while l2.next is not None:
            l2List.append(l2.val)
            l2 = l2.next
        l2List.append(l2.val)

        #find smaller linked list index
        smallListIdx = 1
        if len(l1List) > len(l2List):
            smallListIdx = 2

        dec = 1
        intOutPut = 0
        #sum 0 ~ smaller linked list index
        for i in range(0, len(l[smallListIdx - 1])):
            intOutPut = intOutPut + (l[0][i] + l[1][i]) * dec
            dec = dec * 10

        #sum smaller linked list index ~ bigger linked list index
        for i in range(len(l[smallListIdx - 1]), len(l[1 - (smallListIdx - 1)])):
            intOutPut = intOutPut + l[1 - (smallListIdx - 1)][i] * dec
            dec = dec * 10

        resList = []
        if intOutPut == 0:
            return ListNode(0)

        #set residual list
        while intOutPut != 0:
            dec = 10
            intOutPut, res = divmod(intOutPut, dec)
            resList.append(res)

        #set linked list val
        listNodeList = []
        for i in range(0, len(resList)):
            tempListNode = ListNode(resList[i])
            listNodeList.append(tempListNode)

        if len(resList) == 1:
            return listNodeList[0]

        #set linked list next
        for i in range(0, len(resList) - 1):
            listNodeList[i].next = listNodeList[i + 1]

        return listNodeList[0]
