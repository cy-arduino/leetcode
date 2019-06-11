
void dump(int ** buf, int n){
    printf("matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d\t", buf[i][j]);
        }
        printf("\n");
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int **ret = malloc(n * sizeof(int*));
    for(int i=0; i<n; i++){
        ret[i] = malloc(n*sizeof(int));
        for(int j=0; j<n; j++){
            ret[i][j] = -1;
        }
    }
    
    *returnSize=n;
    *returnColumnSizes = malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        (*returnColumnSizes)[i]=n;
    }
    
    int data=1;
    int direction=0; //0: right, 1: down, 2: left, 3:up
    int row=0, col=0;
    
    bool running = true;
    while(running && data<=n*n){
        int nextRow, nextCol;
        //printf("direction=%d\n", direction);
        if(direction==0){
            //right                
            for(int i=col; i<n; i++){
                if(ret[row][i]==-1){
                    ret[row][i]=data++;
                    col=i;
                }else{
                    break;
                }
            }

            nextRow = row+1;
            if(nextRow < n && ret[nextRow][col]==-1){
                row = nextRow;
                direction =1;
            }else{
                running = false;
            }
        }else if(direction ==1){
            //down         
            for(int i=row; i<n; i++){
                if(ret[i][col]==-1){
                    ret[i][col]=data++;
                    row=i;
                }else{
                    break;
                }
            }

            nextCol = col-1;
            if(nextCol >= 0 && ret[row][nextCol]==-1){
                col = nextCol;
                direction =2;
            }else{
                running = false;
            }
        }else if(direction == 2){
            //left
             for(int i=col; i>=0; i--){
                if(ret[row][i]==-1){
                    ret[row][i]=data++;
                    col=i;
                }else{
                    break;
                }
            }

            nextRow = row-1;
            if(nextRow >=0 && ret[nextRow][col]==-1){
                row = nextRow;
                direction =3;
            }else{
                running = false;
            }
        }else if(direction ==3){
            //up
            for(int i=row; i>=0; i--){
                if(ret[i][col]==-1){
                    ret[i][col]=data++;
                    row=i;
                }else{
                    break;
                }
            }

            nextCol = col+1;
            if(nextCol <n && ret[row][nextCol]==-1){
                col = nextCol;
                direction =0;
            }else{
                running = false;
            }
        }else{
            printf("Error!!\n");
            
        }
        //dump(ret, n);
        
    }
    
    //printf("ret=\n");
    //dump(ret, n);
    
    return ret;
}

