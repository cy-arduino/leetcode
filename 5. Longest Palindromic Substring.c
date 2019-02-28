class Solution:
    def longestPalindrome(self, s: 'str') -> 'str':
        max_str_even=''
        max_str_odd=s[0:1]
        
        if len(s) == 1:
            return s
        
        for i in range(0, len(s)):
            tmp_str_even=''
            tmp_str_odd=''
            
            
            #even len str
            if i < len(s)-1:
                for right in range(i+1, len(s)) :
                    left=i-(right-i-1)
                    if(left < 0):
                        break
                    
                    if(s[left]==s[right]):
                        tmp_str_even=s[left:right+1]
                        #print('got tmp_str_even', tmp_str_even)
                    else:
                        break
                        
            if len(tmp_str_even) > len(max_str_even):
                max_str_even = tmp_str_even
            
            
            #odd len str
            if i > 0:
                for right in range(i+1, len(s)):
                    left = i-(right-i)
                    if left < 0:
                        break
                    
                    if(s[left] == s[right]):
                        tmp_str_odd = s[left:right+1]
                        #print('got tmp_str_odd', tmp_str_odd)
                    else:
                        break
            
            if len(tmp_str_odd) > len(max_str_odd):
                max_str_odd = tmp_str_odd
            
        if len(max_str_odd) > len(max_str_even):
            return max_str_odd
        else:
            return max_str_even
