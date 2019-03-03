# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: 'ListNode', n: 'int') -> 'ListNode':
        myHead = ListNode(-1)
        myHead.next = head
        
        nth = myHead
        l = myHead
        
        #time/space complexity: O(n)
        while l.next != None:
            l=l.next
            if n==0:
                nth=nth.next
            else:
                n-=1
        
        nth.next = nth.next.next
        
        return myHead.next
