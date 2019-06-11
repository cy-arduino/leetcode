int comp(const void *a, const void *b){    
    if( (*(int**)a)[0] ==  (*(int**)b)[0])
        return (*(int**)a)[1] - (*(int**)b)[1] ;
    else
        return (*(int**)a)[0] - (*(int**)b)[0] ;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    //sort intervals
    qsort(intervals, intervalsSize, sizeof(int*), comp);
    
    //for(int i=0; i<intervalsSize; i++){
    //    printf("[%d,%d]\n", intervals[i][0],intervals[i][1]);
    //}
    
    int maxRetSize = 100;
    *returnSize=0;
    (*returnColumnSizes) = (int*) malloc(maxRetSize * sizeof(int));
    int **ret = (int**) malloc(maxRetSize * sizeof(int*)); 
    
    int i=0;
    while(i< intervalsSize){
        int next = i+1;
        
        while(next<intervalsSize){
            if(intervals[i][1] >= intervals[next][0]){
                //printf("merge!\n");
                
                //merge to intervals[i]
                if(intervals[i][1] < intervals[next][1]){
                    intervals[i][1] = intervals[next][1];
                }
                next++;
            }
            else{
                break;
            }
        }
        
        //TODO: realloc ret & returnColumnSizes
        if((*returnSize) +1 >= maxRetSize){
            //printf("realloc\n");
            maxRetSize*=2;
            ret = realloc(ret, maxRetSize * sizeof(int*)); 
            *returnColumnSizes = realloc(*returnColumnSizes, maxRetSize * sizeof(int));
        }
        
        //TODO: (done)malloc and copy 
        //ret[*returnSize] = intervals[i];
        ret[*returnSize] = malloc(2*sizeof(int));
        ret[*returnSize][0] = intervals[i][0];
        ret[*returnSize][1] = intervals[i][1];
        
        (*returnColumnSizes)[(*returnSize)]=2;
        (*returnSize)++;
        
        i=next;        
    }
    
    return ret;
}

