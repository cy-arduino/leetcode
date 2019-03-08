# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: 'ListNode', l2: 'ListNode') -> 'ListNode':     
       
        if l1 == None:
            return l2
        if l2 == None:
            return l1
    
        if l2.val < l1.val:
            head=l2
            main=l2
            other=l1
        else:
            head=l1
            main=l1
            other=l2
            
        while other != None:
            if main.next == None:
                main.next=other
                break
            elif main.next.val >= other.val:
                takenode=other
                other=takenode.next

                takenode.next=main.next
                main.next=takenode
            else:
                main = main.next
                
        return head
