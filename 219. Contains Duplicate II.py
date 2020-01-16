class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        my_nums = {}
        for i in range(len(nums)):
            key = nums[i]
            if key in my_nums:
                if i - my_nums[key][-1] <= k:
                    return True
                my_nums[key].append(i)
            else:
                my_nums[key] = [i]
        
        return False