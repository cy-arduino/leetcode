class Solution:

    def countAndSay(self, n: int) -> str:
        s = ""
        while n > 0:
            if s == "":
                s="1"
            else:
                tmpS = ""
                
                c=""
                cnt = 0
                i=0                
                while i < len(s):
                    if c=="":
                        c=s[i]
                        cnt+=1
                    elif c==s[i]:
                        cnt+=1
                    else:
                        tmpS+=str(cnt)
                        tmpS+=c
                        c=s[i]
                        cnt=1
                    i+=1
                    
                tmpS+=str(cnt)
                tmpS+=c
                s=tmpS
            
            #print(n, s)
            
            n-=1
        return s
