class Solution:
    def swap(self, l, i, j):
        if i != j:
            l[i]^=l[j]
            l[j]^=l[i]
            l[i]^=l[j]
        
    def reverse(self, l):
        for i in range(len(l)//2):
            self.swap(l, i, len(l)-i-1)
    
    def qSortPart(self, a, l, r, pivot):
        self.swap(a, pivot, r)
        
        centerIdx = l
        for i in range(l, r):
            if a[i] < a[r]:
                self.swap(a,i,centerIdx)
                centerIdx +=1
        
        self.swap(a, centerIdx, r)
        return centerIdx
        
    def qSort(self, a, l, r):
        if l<r:
            privot = self.qSortPart(a, l, r, l+(r-l)//2)
            self.qSort(a, l, privot-1)
            self.qSort(a, privot+1, r)
    

        
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        maxIdx = None
        
        for i in range(len(nums)-1, 0-1, -1):
            if maxIdx == None or nums[maxIdx] <= nums[i]:
                maxIdx = i
            else:
                break
                
        if maxIdx != None:
            if maxIdx == 0:
                #3,2,1 -> 1,2,3
                self.reverse(nums)
            else:
                rightMinIdx = None
                for i in range(len(nums)-1, maxIdx-1, -1):
                    if nums[i] > nums[maxIdx-1] and (rightMinIdx==None or nums[rightMinIdx] > nums[i]):
                        rightMinIdx = i
                
                if rightMinIdx != None:
                    self.swap(nums, maxIdx-1, rightMinIdx)
                    self.qSort(nums, maxIdx, len(nums)-1)
                        
