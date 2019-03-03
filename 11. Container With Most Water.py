def min(a, b):
    if a > b:
        return b
    else:
        return a

class Solution:
    def maxArea(self, height: 'List[int]') -> 'int':
        
        #too slow!
        max=0
        for i in range(0,len(height)-1):
            #speedup
            if height[i] == 0:
                continue
                
            if max == 0:
                start = i+1
            else:
                #speedup
                start = i+max//height[i]
            
            #speedup
            if max > (len(height)-i)*height[i]:
                continue
                
            for j in range(start, len(height)):
                #speedup
                if height[j] == 0:
                    continue
                    
                area = (j-i) * min(height[i], height[j])
                if area > max:
                    #print('i,j=', i, ',', height[i], ' ', j, ',', height[j])
                    max=area
            
        return max
        
        
        
