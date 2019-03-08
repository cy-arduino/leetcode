class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:

        i=0
        searchStart = 1
        while i < len(nums):
            if nums[i] != val:
                i+=1
            else:
                if searchStart<i+1:
                    searchStart = i+1
                j=searchStart
                while j < len(nums):
                    if nums[j] != val:
                        tmp=nums[i]
                        nums[i]=nums[j]
                        nums[j]=tmp
                        i+=1
                        break
                    j+=1
                if j ==len(nums):
                    break

        return i
