class Solution:
    def lengthOfLongestSubstring(self, s: 'str') -> 'int':
        max_len=0
        
        idx=0;
        
        for i in range(0,len(s)):
            cur_len=0
            substr=[]
            for j in range(i,len(s)):
                if not s[j] in substr:
                    cur_len+=1
                    substr+=s[j]
                else:
                    break
            if cur_len > max_len:
                max_len = cur_len
        
        return max_len
                    
            
        