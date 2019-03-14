class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        
        for row in range(9):
            stack = []
            for col in range(9):
                c = board[row][col]
                if c != '.':
                    if c in stack:
                        print("check row fail!")
                        return False
                    else:                        
                        stack.append(c)
                        
        for col in range(9):
            stack = []
            for row in range(9):
                c = board[row][col]
                if c != '.':
                    if c in stack:
                        print("check column fail!")
                        return False
                    else:                        
                        stack.append(c)

        for rowBase in range(3):
            for colBase in range(3):
                #print("block!", rowBase,colBase)
                stack = []
                for row in range(rowBase*3, rowBase*3+3):
                    for col in range(colBase*3, colBase*3+3):
                        c = board[row][col]
                        #print("c!", row,col, c)
                        if c != '.':
                            if c in stack:
                                print("check block fail!", rowBase,colBase,row,col, c, stack)
                                return False
                            else:                        
                                stack.append(c)
                     
        return True
