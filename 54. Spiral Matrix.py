class Solution:
    #0: top
    #1: right
    #2: bottom
    #3: left
    def nextSide(self, ori):
        ret = ori+1
        if ret>=4:
            ret=0    
        return ret
    
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ret = []
        side=0
        
        while matrix != []:
            if side == 0:
                #print("side=", side)
                #print(matrix)
                #print(ret)
                ret+=matrix[0]
                del matrix[0]
            if side == 1:
                #print("side=", side)
                #print(matrix)
                #print(ret)
                for i in range(len(matrix)):
                    ret.append(matrix[i][-1])
                    del matrix[i][-1]
					
				#remove empty list!
                if matrix[0]==[]:
                    matrix=[]
            if side == 2:
                #print("side=", side)
                #print(matrix)
                #print(ret)
                for i in range(len(matrix[-1])):
                    ret.append(matrix[-1][-1])
                    del matrix[-1][-1]
                del matrix[-1]
            if side == 3:
                #print("side=", side)
                #print(matrix)
                #print(ret)
                for i in range(len(matrix)-1, -1, -1):
                    ret.append(matrix[i][0])
                    del matrix[i][0]
					
				#remove empty list!
                if matrix[0]==[]:
                    matrix=[]
                    
            side = self.nextSide(side)
            
        return ret