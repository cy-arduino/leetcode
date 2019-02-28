class Solution:
    def c2i(self, c):
        if c=='0':
            return 0
        elif c=='1':
            return 1
        elif c=='2':
            return 2
        elif c=='3':
            return 3
        elif c=='4':
            return 4
        elif c=='5':
            return 5
        elif c=='6':
            return 6
        elif c=='7':
            return 7
        elif c=='8':
            return 8
        elif c=='9':
            return 9
        else:
            return 0
        
        
    def myAtoi(self, str: 'str') -> 'int':
        sign = 1
        sign_found=False
        
        sign_list=['+','-']
        digit_list=['0','1','2','3','4','5','6','7','8','9']
                   
        r = 0
        
        for c in str:
            #print('check :', c)
            if not sign_found:
                if c in sign_list:
                    sign_found = True
                    if c == '-':
                        sign = -1
                        #print('sign=-1')
                elif c in digit_list:
                   sign_found = True
                   r = r*10 + self.c2i(c)
                   #print('ret=', r)
                elif c == ' ':
                    continue
                else:
                    break
            else:
                if c in digit_list:
                   r = r*10 + self.c2i(c)
                   #print('ret=', r)
                else:
                   break
            
                    
        r *= sign      
        
        if r < -2147483648:
            r = -2147483648
        elif r > 2147483647:
            r = 2147483647
        
        return r
