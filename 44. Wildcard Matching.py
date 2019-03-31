class Solution:
    def isMatch2(self, s, p):
        #print('s:', s, "p:", p)
        i,j=0,0
        savedI, savedJ=None,None
        while i < len(s):
            #print(i,j)
            if j < len(p) and (s[i]== p[j] or p[j]=='?'):
                i,j=i+1,j+1
                continue
            if j < len(p) and p[j] == '*':
                savedI, savedJ=i,j
                j+=1
                continue            
            
            #not match!
            if savedJ!= None:
                #rollback
                j=savedJ+1
                i=savedI+1
                savedI=i
                continue
                
            return False
        
        if j < len(p):
            if j+1 == len(p) and p[j]=='*':
                return True
            else:
                return False
        else:
            return True
                
    '''
    #2nd code: timeout
    def isMatch2(self, s, p):
        #print('s:', s, "p:", p)
        i=0;j=0
        while i < len(s):   
            if j < len(p):
                if p[j] == '*':
                    #print('*')
                    if j+1 < len(p):
                        for k in range(i, len(s)):
                            if (s[k] == p[j+1] or p[j+1]=='?') and self.isMatch2(s[k:], p[j+1:]):
                                return True
                        return False
                    else:
                        return True    
                elif s[i] == p[j] or p[j] == '?':
                    #print('? or a')
                    i+=1
                    j+=1
                else:
                    #s[i] != p[j]
                    return False
            else:
                return False
                
        if j < len(p):
            if j+1 == len(p) and p[j]=='*':
                return True
            else:
                return False
        else:
            return True
    ''' 
    def isMatch(self, s, p):
        #print('p:', p)
        p1 = ''
        c = None
        for i in range(len(p)):
            if c=='*' and p[i]=='*':
                pass
            else:
                c=p[i]
                p1+=c
        
        #print('p1:', p1)
        return self.isMatch2(s,p1)
        



'''
#1st code: timeout
class Solution:
    def isMatch(self, s, p):
        #print('s:', s, "p:", p)
        if p == '':
            if s == '':
                return True
            else:
                return False
            
        if p[0] == '?':
            if s != '':
                return self.isMatch(s[1:], p[1:])
            else:
                return False
            
        elif p[0] == '*':
            # ff p to latest *
            cur_p = 0
            for j in range(1, len(p)):
                if p[j]=='*':
                    cur_p = j
                else:
                    break
            p=p[cur_p+1:]
            if p == '':
                #latest p is *
                return True
            else:    
                for i in range(len(s)):
                    if self.isMatch(s[i:], p):
                        return True
                return False
        elif p[0] == s[0:1]:
            return self.isMatch(s[1:], p[1:])
        else:
            return False
'''
