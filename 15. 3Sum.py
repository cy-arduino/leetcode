class Solution:
    def threeSum(self, nums):
        nums.sort()
        print(nums)
        
        ret = []
        for i in range(0, len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue;
                
            l = i+1
            r = len(nums)-1
            
            while l < r:
                s = nums[i]+nums[l]+nums[r]
                if s == 0:
                    print('==>', i, l, r)
                    ret.append([nums[i],nums[l],nums[r]])
                    
                    l+=1
                    while l<r and nums[l]==nums[l-1]:
                        l+=1
                elif s > 0:
                    r-=1
                    while r>l and nums[r]==nums[r+1]:
                        r-=1
                elif s < 0:
                    l+=1
                    while l<r and nums[l]==nums[l-1]:
                        l+=1
            
        return ret
