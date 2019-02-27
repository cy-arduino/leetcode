# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(0)
        h = head
        
        i=l1
        j=l2
        
        carry = 0
        while not(i==None and j==None):
           
            sum = carry + (i.val if i!=None else 0) + (j.val if j!=None else 0)
            carry = sum//10
            
            i=(i.next if i!=None else None)
            j=(j.next if j!=None else None)

            h.next = ListNode(sum%10)
            
            h = h.next
        
        if carry > 0:
            h.next = ListNode(carry)
        
        return head.next