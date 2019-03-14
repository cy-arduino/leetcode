class Solution:
    def find(self, nums: 'List[int]', target: 'int', l, r)-> 'int':
        ret = -1
        
        if l==r:
            pass
        elif l+1==r:
            if nums[l]==target:
                ret =  l
        else:
            mid = l + (r-l)//2
            
            if nums[l] <= nums[mid-1]:
                #left is sorted
                if target >= nums[l] and target <= nums[mid-1]:
                    #may in left
                    ret = self.find(nums, target, l, mid)
                else:
                    #may in right
                    ret = self.find(nums, target, mid, r)
            else:
                #right is sorted
                if target >=nums[mid] and target <= nums[r-1]:
                    #may in left
                    ret = self.find(nums, target, mid, r)
                else:
                    #may in right
                    ret = self.find (nums, target, l, mid)
        return ret
                
        
    
    def search(self, nums: 'List[int]', target: 'int') -> 'int':
        return self.find(nums, target,0, len(nums))
        
        
        
