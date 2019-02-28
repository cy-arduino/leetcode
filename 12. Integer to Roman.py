ROMAN=[['M', 1000],['D', 500],['C', 100],['L', 50],['X', 10],['V', 5],["I", 1]]

class Solution:

    def intToRoman(self, num: 'int') -> 'str':
        
        tmp_num=num
        
        RET=''
        
        for i in range(0, len(ROMAN),2):
            letter=ROMAN[i][0]
            value=ROMAN[i][1]
            
            repeat=tmp_num//value
            mod=int(((tmp_num%value)/value)*10)
            #print('i=', i, ' repeat=', repeat, " mod=", mod)
            
            if repeat >0:
                for j in range(0, repeat):
                    RET+=letter
                        
            if repeat >= 0:
                if mod == 4:
                    RET+=ROMAN[i+2][0]
                    RET+=ROMAN[i+1][0]
                elif mod == 9:
                    RET+=ROMAN[i+2][0]
                    RET+=ROMAN[i][0]
                elif mod <4:
                    for j in range(0, mod):
                        RET+=ROMAN[i+2][0]
                elif mod < 9:
                    RET+=ROMAN[i+1][0]
                    for j in range(5, mod):
                        RET+=ROMAN[i+2][0]
            
            if i == len(ROMAN)-1:
                break
            else:
                tmp_num = tmp_num%ROMAN[i+2][1]
                #print('RET=', RET)
        
        return RET
