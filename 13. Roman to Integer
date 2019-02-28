ROMAN={'M':1000, 'D':500, 'C':100, 'L':50, 'X':10, 'V':5, 'I':1}

class Solution:
    def romanToInt(self, s: 'str') -> 'int':
        #recursive
        '''
        RET = 0
        
        if len(s) != 0:        
            cur_value = ROMAN[s[0]]
            next_value = -1
            if len(s) > 1:
                next_value=ROMAN[s[1]]

            if next_value > cur_value:
                RET += next_value-cur_value
                RET += self.romanToInt(s[2:])
            else:
                RET += cur_value
                RET += self.romanToInt(s[1:])
        
        return RET 
        '''
        
        #direct
        RET = 0
        i=0        
        while i < len(s):
            cur_value = ROMAN[s[i]]
            next_value = -1
            if i+1 < len(s):
                next_value=ROMAN[s[i+1]]
            
            if next_value > cur_value:
                RET += next_value-cur_value
                i+=2
            else:
                RET += cur_value
                i+=1
        return RET
