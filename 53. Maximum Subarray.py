class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sums=[]
        
        for i in nums:
            if sums == []:
                sums.append(i)
            else:
                sums.append(sums[-1]+i)
            
        print(sums)
        
        max = None
        base = 0
        for i in sums:
            if max == None or max < i-base:
                max = i-base
                
            if base > i:
                base = i
        
        return max
