from enum import Enum

class Solution:
    def isMatch(self, s: 'str', p: 'str') -> 'bool':
        #print('isMatch: s=', s , " p=", p)

        if p == '':
            if s == '':
                return True
            else:
                return False
        
        ret = False    
        
        if s =='':
            if p[1:2] == '*':
                return self.isMatch(s, p[2:])

        else:
            if p[1:2] == '*':
                #match zero to many
                if self.isMatch(s, p[2:]):
                        ret = True
                else:
                    for i in range(0, len(s)):
                        if s[i] == p[0] or p[0] == '.':
                            if self.isMatch(s[i+1:], p[2:]):
                                ret = True
                        else:
                            break
            else:
                if s[0] == p[0] or p[0] == '.':
                    ret = self.isMatch(s[1:], p[1:])
                else:
                    ret = False
                    
        #print('Return ',ret)
        return ret
        
        
        
        
