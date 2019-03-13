class Solution:
    def longestValidParentheses(self, s: str) -> int:
        longest=0
        
        
        #'(':-1, ')':-2
        stack=[]
        i=0
        while i < len(s):
            #print('i:', i)
            if s[i] == '(':
                stack.append(-1)
                #print("stack:", stack)
            if s[i] == ')':
                #try merge
                tmpLen = 0
                while stack != []:
                    top = stack.pop()
                    #print("stack:", stack)
                    if top > 0:
                        tmpLen += top
                    elif top == -1:
                        #found a mapping '('
                        tmpLen+=2
                        
                        if stack!=[] and stack[-1] > 0:
                            tmpLen+=stack.pop()
                        
                        stack.append(tmpLen)
                        #print("stack:", stack)
                        break
                    else:
                        #not found
                        stack.append(-2)
                        break
                
                if longest < tmpLen:                    
                    longest = tmpLen
                    #print('update longest:', longest)
                    
            i+=1
        
        return longest
                
