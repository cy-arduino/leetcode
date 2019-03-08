class Solution:
    def removeDuplicates(self, nums: 'List[int]') -> 'int':
        print('input:', nums)
        
        if len(nums) == 0:
            return 0
        
        
        c=nums[0]
        ret = 1
        for n in nums:
            if n==c:
                pass
            else:
                c=n
                ret+=1
                nums[ret-1] = c
        
        print('len=', ret)
        return ret 
