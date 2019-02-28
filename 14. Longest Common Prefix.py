class Solution:
    def longestCommonPrefix(self, strs: 'List[str]') -> 'str':
        RET = ''
        if len(strs) == 1:
            RET=strs[0]
        elif len(strs) > 1:        
            for col in range(0, len(strs[0])):
                same = 1
                for row in range(1, len(strs)):
                    if strs[row][col:col+1] == '' or strs[row][col:col+1] != strs[0][col:col+1] :
                        same = 0
                if same == 1:
                    RET += strs[0][col:col+1]
                else:
                    break

        return RET
            
        
