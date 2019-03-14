class Solution:
    def recursive(self, candidates, target, selected, sum):
        ret = []
        for i in range(len(candidates)):
            c = candidates[i]
            sum2 = sum + c
            #print('sel:', selected, ' c=', c)
            selected2 = [i for i in selected]
            selected2.append(c)
            #print('sel2:', selected2)
            
            if sum2 < target:
                r = self.recursive(candidates[i:], target, selected2, sum2)
                if r != []:
                    ret += r
            elif sum2 == target:
                #print('found!!\n')
                ret += [selected2]
            else:
                break
        
        #print('ret=', ret)
        return ret
                
        
        
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        return self.recursive(candidates, target, [], 0)
        
            
        
