class Solution:
    def convert(self, s: 'str', numRows: 'int') -> 'str':
        list_idx=0
        list_dir=1
        
        if numRows==1:
            return s
        
        l=[]
        for i in range(0, numRows):
             l.append([])
        
        for c in range(0, len(s)):
            l[list_idx].append(s[c])
            if (list_idx + list_dir) >= numRows:
                list_dir=-1
            if (list_idx + list_dir) <0:
                list_dir=1
            list_idx += list_dir
        
        ret_str = ''
        for i in range(0, numRows):
            for j in l[i]:
                ret_str+=j
        return ret_str
