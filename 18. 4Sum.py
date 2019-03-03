class Solution:
    def threeSum(self, nums, target):
        #nums.sort()
        #print(nums)
        
        ret = []
        for i in range(0, len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue;
                
            l = i+1
            r = len(nums)-1
            
            while l < r:
                #print('==>', i, l, r)
                s = nums[i]+nums[l]+nums[r] - target
                if s == 0:
                    #print('==>', i, l, r)
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
        
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        ret = []
        
        nums.sort()
        print(nums)

        
        if len(nums) < 4 or nums[-1] < 0 or nums[0] > 0:
            #speedup
            pass
        else:
            for i in range(len(nums)-3):
                #print('found 3sum=', (target-nums[i]))
                s=self.threeSum(nums[i+1:], (target-nums[i]))
                #print(s)
                for j in s:
                    elem = [nums[i]]+j
                    if not elem in ret:
                        ret+=[elem]
        
        return ret
