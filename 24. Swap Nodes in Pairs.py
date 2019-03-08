# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#assume h/h.next/h.next.next exist
def swapNextTwoNodes(h):
    tmp=h.next.next
    h.next.next=tmp.next
    tmp.next=h.next
    h.next=tmp
        

class Solution:
    def swapPairs(self, head: 'ListNode') -> 'ListNode':
        ret=None
        
        my_head=ListNode(-1)
        my_head.next=head
      
        h=my_head
        while h.next != None:            
            
            if h.next.next == None:
                break
            else:
                swapNextTwoNodes(h)
                h=h.next.next
        
        return my_head.next
