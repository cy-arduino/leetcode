
bool chk(char** board, int boardSize, int* boardColSize, char * word, int row, int col){
    //printf("chk: word=%s, row=%d, col=%d\n", word, row, col);
    bool ret = false;
          
    if(word[0] == board[row][col]){
        if(strlen(word)==1)
            //done
            return true;
        
        char c = board[row][col];                
        board[row][col] = '\0';    
        
        ///////////////////////////////
        //up
        if(row-1 >= 0){
            ret = chk(board, boardSize, boardColSize, word+1, row-1, col);
            if(ret)
                return true;
        }

        //down
        if(row+1 <boardSize){
            ret = chk(board, boardSize, boardColSize, word+1, row+1, col);
            if(ret)
                return true;
        }

        //left
        if(col-1 >= 0){
            ret = chk(board, boardSize, boardColSize, word+1, row, col-1);
            if(ret)
                return true;
        }

        //right  
        if(col+1 < boardColSize[row]){
            ret = chk(board, boardSize, boardColSize, word+1, row, col+1);
            if(ret)
                return true;
        }
        ///////////////////////////////
        
        
        board[row][col] = c;
    }

    return ret;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    bool ret = false;
    
    for(int row=0; row<boardSize; row++){
        for(int col=0; col<boardColSize[row]; col++){
            ret = chk(board, boardSize, boardColSize, word, row, col);       
            if(ret)
                return true;
        }
    }

    return ret;
}

