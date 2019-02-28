class Solution:
    def reverse(self, x: 'int') -> 'int':
        
        ret = 0
        sign = 1
        if x < 0:
            sign = -1
            x *= -1
            
        if x == 0:
            return 0
        
        while x > 0:
            ret = ret * 10 + x%10
            x //= 10 
        
        ret*=sign
        
        if ret < -2147483648 or ret > 2147483647:
            ret = 0
            
        return ret
