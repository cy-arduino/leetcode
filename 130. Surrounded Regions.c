//ret: surrounded
bool markRegion(char **board, int i, int j, int row, int col, char from, char to){
    //printf("%s: i=%d, j=%d\n",__func__, i, j);
    if(i==0 || i==row-1 || j==0 ||j==col-1){
        return false;
    }
    
    board[i][j] = to;
    
   
    //left
    if(board[i][j-1] == from){
        if(!markRegion(board, i, j-1, row, col, from, to))
            return false;
    }
    //right
    if(board[i][j+1] == from){
        if(!markRegion(board, i, j+1, row, col, from, to))
            return false;
    }
    //up
    if(board[i-1][j] == from){
        if(!markRegion(board, i-1, j, row, col, from, to))
            return false;
    }
    //down
    if(board[i+1][j] == from){
        if(!markRegion(board, i+1, j, row, col, from, to))
            return false;
    }
    
    return true;
}

    

//assume board is a rectengle
void solve(char** board, int boardSize, int* boardColSize){
    for(int i=0; i<boardSize; i++){
        for(int j=0; j<boardColSize[i]; j++){
            if(board[i][j] == 'O'){
                //printf("found 'O', i=%d, j=%d, row=%d, col=%d\n", i, j, boardSize, boardColSize[0]);
                bool surrounded = markRegion(board, i, j, boardSize, boardColSize[0], 'O', 'c');
                //printf("surrounded = %d\n", surrounded);
                if(surrounded){
                    markRegion(board, i, j, boardSize, boardColSize[0], 'c', 'X');
                }else{
                    markRegion(board, i, j, boardSize, boardColSize[0], 'c', 'O');
                }
            }
        }
    }

}

