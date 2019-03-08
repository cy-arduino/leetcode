class Solution:
    
    def isvalid(self, str):
        stack=''
        
        for c in str:
            stack+=c
            if c == ')':
                if len(stack) < 2:
                    break
                elif stack[-2:] == '()':
                    stack=stack[:-2]
                    
        return len(stack) == 0
    
    def recursive(self, l: 'str', r: 'str', stack:'str') -> 'List[str]':
        #print('l=', l, ' r=', r, ' stack=', stack)
        
        ret=[]
        
        if l=='' and r=='':
            if self.isvalid(stack):
                ret.append(stack)
        else:
            if l!='':
                result = self.recursive(l[1:], r, stack + l[-1:])
                if result != []:
                    ret+=result
            if r!='':
                result = self.recursive(l, r[1:], stack + r[-1:])
                if result != []:
                    ret+=result
        #print('ret=', ret)
        return ret
    
    def generateParenthesis(self, n: 'int') -> 'List[str]':
        l=''
        r=''
        stack=''

        for i in range(n):
            l+='('
            r+=')'
            
        return self.recursive(l, r, stack)
        
