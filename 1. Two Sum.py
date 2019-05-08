class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict={}
        for i in range(len(nums)):
            if dict.get(str(target-nums[i])) != None:
                return [dict[str(target-nums[i])], i]
            else:
                dict[str(nums[i])]=i
        
