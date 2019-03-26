class Solution:
    def findLeft(self, height, l, r):
        #print("findLeft:", l, r)
        
        ret = 0
        if r - l > 1:            
            h=None
            h_idx=None
            for i in range(l,r):
                if h==None or height[i] >= h:
                    h=height[i]
                    h_idx=i
            if r - h_idx > 1:
                area = 0
                for i in range(h_idx+1,r):
                    area += h-height[i]
                ret += area
                
            ret += self.findLeft(height, l, h_idx)
        return ret
    
    def findRight(self, height, l, r):
        #print("findRight:", l, r)
        
        ret = 0
        if r - l > 1:
            h=None
            h_idx=None
            for i in range(l,r):
                if h==None or height[i] >= h:
                    h=height[i]
                    h_idx=i
            if h_idx-l > 0:
                area = 0
                for i in range(l,h_idx):
                    area += h-height[i]
                ret += area
                
            ret += self.findRight(height, h_idx+1, r)
        return ret
        
    def trap(self, height: List[int]) -> int:
        ret = 0
        
        #find highest h and it's index
        l=0
        r=len(height)
        if r-l > 1:
            h=None
            h_idx=None
            for i in range(l,r):
                if h==None or height[i] > h:
                    h=height[i]
                    h_idx=i
        
            #find left
            ret += self.findLeft(height, 0, h_idx)
            
            #find right
            ret += self.findRight(height, h_idx+1, len(height))
        
        
        return ret 
