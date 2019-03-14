class Solution:
    def searchInsertImpl(self, nums: List[int], target: int, l, r) -> int:
        
        ret = -1
        if l==r:
            pass
        else:
            if r-l == 1:
                if target <=nums[l]:
                    ret = l
                else:
                    ret = l+1
            else:
                mid = l +(r-l)//2
                if nums[mid] > target:
                    ret = self.searchInsertImpl(nums, target, l, mid)
                else:
                    ret = self.searchInsertImpl(nums, target, mid, r)
        
        return ret
        
    def searchInsert(self, nums: List[int], target: int) -> int:
        return self.searchInsertImpl(nums, target, 0, len(nums))
        
        
