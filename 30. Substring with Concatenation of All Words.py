class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        ret = []
        lenWord = 0
        if len(words) > 0:
            lenWord = len(words[0])
        
        if lenWord > 0 and len(s) >= lenWord * len(words):
            for i in range(len(s)-lenWord * len(words)+1):
                mWords = [w for w in words]
                #print(i, mWords)
                for j in range(len(words)):
                    if s[j*lenWord+i:j*lenWord+i+lenWord] in mWords:
                        mWords.remove(s[j*lenWord+i:j*lenWord+i+lenWord])
                
                if mWords == []:
                    #found
                    ret.append(i)               
                
        
        return ret
        
