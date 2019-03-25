class Solution:
    def recursive(self, candidates, current, target):
        ret = []
        
        last = None
        for i in range(len(candidates)):
            if candidates[i] != last:
                last = candidates[i]
                if target-candidates[i] > 0:
                    ret += self.recursive(candidates[i+1:], current+[candidates[i]], target-candidates[i])
                elif target-candidates[i] == 0:
                    ret.append(current+[candidates[i]])
        
        return ret
    
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        
        #remove unnecessary part
        candidates.sort()
        for i in range(len(candidates)):
            if candidates[i] > target:
                candidates = candidates[:i]
                break
        
        current = []
        return self.recursive(candidates, current, target)
