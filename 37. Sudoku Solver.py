digit=['1','2','3','4','5','6','7','8','9']

def recursive(board: 'List[List[str]]') -> 'bool':
    for row in range(9):
        for col in range(9):
            if board[row][col]=='.':
                for i in digit:
                    #check same row
                    if i in board[row]:
                        #invalid, check netxt i
                        continue                       

                    #check same column
                    invalid=False
                    for j in range(9):
                        if board[j][col] == i:
                            #invalid, break
                            invalid=True
                            break
                    if invalid:
                        #invalid, check netxt i
                        continue
                    
                    
                    #check block
                    invalid=False
                    for tmp_row in range(row//3*3, row//3*3+3):
                        for tmp_col in range(col//3*3,col//3*3+3):
                            if board[tmp_row][tmp_col] == i:
                                invalid=True
                                break
                        if invalid:
                            break
                    if invalid:
                        continue
                    
                    #found a suitable i, try it
                    board[row][col]=i
                    ret  = recursive(board)
                    if ret:
                        return True;
                    else:
                        #failed, restore
                        board[row][col]='.'               
                        continue
                
                # no suitable i
                return False
    return True

class Solution:
    def solveSudoku(self, board: 'List[List[str]]') -> 'None':
        """
        Do not return anything, modify board in-place instead.
        """
        print('ret=', recursive(board))

                        
        
