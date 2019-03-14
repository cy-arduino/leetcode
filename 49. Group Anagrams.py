
#solution1
val={
    'a':1<<0,
    'b':1<<1,
    'c':1<<2,
    'd':1<<3,
    'e':1<<4,
    'f':1<<5,
    'g':1<<6,
    'h':1<<7,
    'i':1<<8,
    'j':1<<9,
    'k':1<<10,
    'l':1<<11,
    'm':1<<12,
    'n':1<<13,
    'o':1<<14,
    'p':1<<15,
    'q':1<<16,
    'r':1<<17,
    's':1<<18,
    't':1<<19,
    'u':1<<20,
    'v':1<<21,
    'w':1<<22,
    'x':1<<23,
    'y':1<<24,
    'z':1<<25
}

'''
#solution2
def match(a,b):
    
    if len(a) != len(b):
        return False

    b_list=[c for c in b]
    #print(b_list)
    
    for c in a:
        if c in b_list:
            b_list.remove(c)
        else:
            return False
    
    if b_list==[]:
        return True
    else:
        return False
'''

def getKey(elem):
    return elem[0]

class Solution:
    def groupAnagrams(self, strs: 'List[str]') -> 'List[List[str]]':
        
        '''
        #solution2
        ret=[]     
        while strs!=[]:
            
            head=strs[0]            
            del strs[0]
            
            group=[head]
            rm=[]
            for i in range(len(strs)):
                s=strs[i]    
            
                if match(head, s):
                    group.append(s)
                    rm.append(i)
            rm.sort(reverse=True)
            for i in rm:
                del strs[i]
        
            ret.append(group)
        
        return ret
        '''

        
        #solution1
        ret=[]
        map=[]
        for i in range(len(strs)):
            s=strs[i]
            sum=0
            for c in s:
                v=val[c]
                while (sum & v)>0:
                    v<<=26
                sum|=v
            #print("str:", s, " val:", sum)
            map.append([sum, s])
        
        map.sort(key=getKey)
        
        while(map != []):
            head=map[0]
            del map[0]
            group=[head[1]]
            #print('group:', group)
            #print('map:', map)
            
            
            d=[]
            for i in range(len(map)):
                #print('check ', map[i])
                if map[i][0] == head[0]:
                    #print('add ', map[i])
                    group.append(map[i][1])
                    d.append(i)
                elif map[i][0] >head[0]:
                    break
            d.sort(reverse=True)
            for i in d:
                del map[i]

            #print('map after:', map)
            ret.append(group)
            
        return ret
        
        
            
            
            
