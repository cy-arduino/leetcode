class Solution:
    def recursive(self, nums: 'List[int]', selected: 'List[int]', ) -> 'List[List[int]]':
        #print('nums=', nums, ' selected=', selected)
        ret=[]
        if nums == []:
            ret.append(selected)
        else:           
            for i in nums:
                new_nums = []+nums
                new_nums.remove(i)
                new_selected = []+selected
                new_selected.append(i)
                ret += self.recursive(new_nums, new_selected)
        
        #print('return: ', ret)
        return ret
    
    def permute(self, nums: 'List[int]') -> 'List[List[int]]':
        return self.recursive(nums,[])
        