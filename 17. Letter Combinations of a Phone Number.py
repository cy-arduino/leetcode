map={'2':"abc", '3':"def", '4':"ghi", '5':"jkl", '6':"mno", '7':"pqrs", '8':"tuv", '9':"wxyz"}

class Solution:    
    def recursive_impl(self, digits: 'str', result: 'List[str]')-> 'List[str]':
        #print('digits:', digits)
        #print('result:', result)
        ret=[]
        
        if len(digits) > 0:
            c = digits[0]
            if len(result) == 0:
                for i in map[c]:
                    ret.append(i)
            else:
                for ori in result:
                    for n in map[c]:
                        ret.append(ori+n)
            #print('ret=', ret)
                
            ret = self.recursive_impl(digits[1:], ret)
        else:
            ret=result
            
        return ret
    
    def letterCombinations(self, digits: 'str') -> 'List[str]':
        return self.recursive_impl(digits, [])
        
