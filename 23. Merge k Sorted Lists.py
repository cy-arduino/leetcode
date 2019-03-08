# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        idx = []
        
        ret = ListNode(0)
        next = ret
        
        #print(lists)
        
        for i in range(len(lists)):
            #print(i)
            if lists[i] != [] and lists[i]!= None:
                idx.append(lists[i])

        while idx != []:
            min = None
            min_idx = None
            #print(idx)
            for i in range(len(idx)):
                if min == None or min > idx[i].val:
                    min = idx[i].val
                    min_idx = i
                    
            #print(min_idx, min)

            if idx[min_idx].next == None:
                del idx[min_idx]
            else:
                idx[min_idx] = idx[min_idx].next
            next.next = ListNode(min)
            next = next.next
        
        
        return ret.next
            
