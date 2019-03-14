class Solution:
    intStrMap = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    def toStr(self, i):
        return self.intStrMap[i]
    
    def toInt(self, s):
        return self.intStrMap.index(s)
        
    
    def myAdd(self, num1, num2):
        len1 = len(num1)
        len2 = len(num2)
        
        #print('len=', len1, len2)
        
        max_len = len1
        if len2 > len1:
            max_len = len2
        
        ret = ''
        
        c = 0 #carry
        for i in range(-1, -1*max_len-1, -1):
            #print('i=', i)
            
            if i < -1*len1:
                d1=0
            else:
                d1 = self.toInt(num1[i])
            
            if i < -1*len2:
                d2=0
            else:
                d2 = self.toInt(num2[i])
            
            s = c + d1 + d2
            
            c = s//10
            ret = self.toStr(s%10) + ret
        
        if c > 0:
            ret = self.toStr(c) + ret
            
            
        return ret
        
    def multiply(self, num1: str, num2: str) -> str:
        
        ret = '0'
        
        for i in range(len(num2)):
            d = self.toInt(num2[i])
            for j in range(d):
                ret=self.myAdd(ret,num1)
            
            if i < len(num2) -1:
                #has next
                ret = ret + '0'
        
        while len(ret) > 1 and ret[0] == '0':
            ret = ret[1:]
        
        
        return ret
        
