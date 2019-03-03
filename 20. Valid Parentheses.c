left=['(', '[', '{']
right=[')', ']', '}']
class Solution:
    def isValid(self, s: 'str') -> 'bool':
        stack = []
        for c in s:
            #print('c=', c)
            if c in left:
                stack.append(c)
                #print('stack=', stack)
            else:
                if len(stack) == 0:
                    return False
                    
                if left[right.index(c)] == stack[-1]:
                    del stack[-1]
                    #print('stack=', stack)
                else:
                    return False
        
        if len(stack) == 0:
            return True
        else:
            return False
