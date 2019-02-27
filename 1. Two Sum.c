def takedata(i):
    return i[1]

class Solution:
    def twoSum(self, nums: 'List[int]', target: 'int') -> 'List[int]':
        
        my_nums = []
        for i in range(len(nums)):
            my_nums.append((i, nums[i]))

        my_nums.sort(key=takedata)
        
        #print(my_nums)
        
        ret = []
        for i in range(len(my_nums)):
            for j in range(i+1, len(my_nums)):
                if my_nums[i][1] + my_nums[j][1] < target:
                    continue
                elif my_nums[i][1] + my_nums[j][1] > target:
                    break
                else:
                    #found
                    #print(nums[i], nums[j])
                    #print(ori_nums)
                    ret.append(my_nums[i][0])
                    ret.append(my_nums[j][0])
        
        return ret 
        '''
        ori_nums=[]
        for i in nums:
            ori_nums.append(i)
        #print(ori_nums)
        
        nums.sort()
        #print(nums)
        
        ret = []
        
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] < target:
                    continue
                elif nums[i] + nums[j] > target:
                    break
                else:
                    #found
                    #print(nums[i], nums[j])
                    #print(ori_nums)
                    ret.append(ori_nums.index(nums[i]))
                    ret.append(ori_nums.index(nums[j]))
        
        return ret 
        '''