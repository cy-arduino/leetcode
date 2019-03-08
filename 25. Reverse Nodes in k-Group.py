# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#[framePrev]->[frame: k nodes]->[frameNext]
class Solution:
        
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        ret = ListNode(0)
        ret.next = head

        framePrev = ret
        while framePrev !=None:            
            nodeStack = []
            n = framePrev
            for i in range(k):
                if n.next != None:
                    nodeStack.append(n.next)
                    n = n.next
                else:
                    break
            
            if len(nodeStack)==k:                
                #reverse nodes...
                frameNext = n.next
                n=framePrev
                while nodeStack != []:
                    n.next = nodeStack[-1]
                    n = n.next
                    del nodeStack[-1]
                
                n.next = frameNext
                framePrev = n                
            else:
                framePrev = None

        return ret.next
