class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        lenHaystack = len(haystack)
        lenNeedle = len(needle)
        
        ret = 0
        
        if lenNeedle > 0:
            ret = -1
            if lenHaystack >= lenNeedle:
                for i in range(lenHaystack-lenNeedle+1):
                    if haystack[i:i+lenNeedle]==needle:
                        #found
                        ret = i
                        break
        
        return ret
