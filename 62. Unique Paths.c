

int findPaths(int **map, int m, int n, int row, int col){
    //printf("findPaths: row=%d, col=%d, ans");
    
    int ret;
    if(row >=m || col >=n){
        ret = 0;
    }    
    else if(map[row][col] != 0){
        ret = map[row][col];
    }else if(col == n-1 && row == m-1){
        map[row][col] = 1; 
        ret = map[row][col];
    }else{
        map[row][col] = findPaths(map, m, n, row, col+1) + findPaths(map, m, n, row+1, col);
        ret = map[row][col];
    }
    
    return ret;
}

int uniquePaths(int m, int n){
    
    //store all possible path in each map[row][column] to speedup
    int **map = malloc(m * sizeof(int*));
    for(int i=0; i<m; i++){
        map[i] = malloc(n * sizeof(int));
        for(int j=0; j<n; j++){
            map[i][j] = 0;
        }
    }
    
    int ans= findPaths(map, m, n, 0, 0);
    
    return ans;
}

