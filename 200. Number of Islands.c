void dump(char** grid, int gridSize, int* gridColSize){
    printf("\ndump:\n");
    for(int row=0; row<gridSize; row++){
        for(int col=0; col<gridColSize[row]; col++){
            printf("%c ", grid[row][col]);
        }
        printf("\n");
    }
    
}

void extend(char** grid, int gridSize, int* gridColSize, int islandId, int row, int col){
    //printf("extend: row=%d, col=%d, islandId=%d\n", row, col, islandId);
    if(grid[row][col] == '1'){
        grid[row][col] = 'a' + islandId;
        
        if(row-1 >=0){
            extend(grid, gridSize, gridColSize, islandId, row-1, col);
        }
        if(row+1 < gridSize){
            extend(grid, gridSize, gridColSize, islandId, row+1, col);
        }
        if(col-1 >=0){
            extend(grid, gridSize, gridColSize, islandId, row, col-1);
        }
        if(col+1 < gridColSize[row]){
            extend(grid, gridSize, gridColSize, islandId, row, col+1);
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){

    int islandId = 0;
    
    for(int row=0; row<gridSize; row++){
        for(int col=0; col<gridColSize[row]; col++){
            if(grid[row][col] == '1'){
                extend(grid, gridSize, gridColSize, islandId, row, col);
                islandId++;
                
                //dump(grid, gridSize, gridColSize);
            }
        }
    }
    
    return islandId;

}

