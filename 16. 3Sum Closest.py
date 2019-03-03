class Solution:
    def threeSumClosest(self, nums: 'List[int]', target: 'int') -> 'int':
        closest = None
        closest_diff = None
        
        nums.sort()
        
        for i in range(len(nums)-2):
            l = i+1
            r = len(nums)-1
            
            while l < r:
                s = nums[i]+nums[l]+nums[r]
                
                if s==target:
                    #found the best solution
                    return target
                
                diff = s-target
                if diff < 0:
                    diff *=-1
                
                if closest == None or diff < closest_diff:                    
                    closest = s
                    closest_diff = diff
                
                if s > target-diff:
                    r-=1

                elif s < target+diff:                
                    l+=1

                else:
                    break
                       
        return closest
    
            
