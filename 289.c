

void gameOfLife(int** board, int boardSize, int* boardColSize){
    int rowSize = boardSize;
    int colSize = boardColSize[0];
    printf("rowSize,colSize = %d,%d\n", rowSize, colSize);
    
    int **nextBoard = (int **)calloc(rowSize, sizeof(int *));
    for(int i=0; i<rowSize; i++){
        nextBoard[i] = (int *)calloc(colSize, sizeof(int));
    }
    
    for(int row=0; row<rowSize; row++){
        for(int col=0; col<colSize; col++){
            int live = 0;
            //printf("## board[%d][%d]\n", row, col);
            for(int i=(row-1)>=0?row-1:row; i<=((row+1)<rowSize?row+1:row); i++){
                for(int j=(col-1)>=0?col-1:col; j<=((col+1)<colSize?col+1:col); j++){
                    if(i==row && j==col){
                        continue;
                    }
                    //printf("check board[%d][%d]\n", i, j);
                    if(board[i][j]){
                        live++;
                    }
                }
            }
            
            if(board[row][col]){
                //live
                if(live == 2 || live ==3){
                    //still live, rule 2
                    nextBoard[row][col] = 1;
                }else{
                    //live->dead, rule1 1&3
                    nextBoard[row][col] = 0;
                }
            }else{
                //dead
                if(live==3){
                    //dead->live, rule4
                    nextBoard[row][col] = 1;
                }else{
                    //still dead
                    nextBoard[row][col] = 0;
                }
            }
        }
    }
    
    for(int row=0; row<rowSize; row++){
        for(int col=0; col<colSize; col++){
            board[row][col] = nextBoard[row][col];
        }
    }
    
    for(int i=0; i<rowSize; i++){
        free(nextBoard[i]);
    }
    free(nextBoard);
    
    return;
}

