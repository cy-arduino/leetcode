
int combinations(int n, int ****solutions, int rootIdx, int start, int end){
    //printf("%s: rootIdx=%d, start=%d, end=%d\n", __func__, rootIdx, start, end);
	if(start >= end)
		return 0;
		
	if(start+1 == end)
		return 1;
	
    
	
    //check if calculated
    if((*solutions) && (*solutions)[rootIdx] && (*solutions)[rootIdx][start] && (*solutions)[rootIdx][start][end]){
        return (*solutions)[rootIdx][start][end];
    }
	
	
    
	int ret = 0;	
	
	//left
	int left=0;
	for(int nextRootIdx=start; nextRootIdx<rootIdx; nextRootIdx++){
		left+=combinations(n ,solutions, nextRootIdx, start, rootIdx);
	}
    //printf("left = %d\n", left);
    if(!left)
        left = 1;
	
    
	//right
	int right=0;
	for(int nextRootIdx=rootIdx+1; nextRootIdx < end; nextRootIdx++){
		right+=combinations(n ,solutions, nextRootIdx, rootIdx+1, end);
	}
    //printf("right = %d\n", right);
    if(!right)
        right = 1;
    
    ret = left * right;
    
    
    //save answer to reuse!
    if(!(*solutions)){
        (*solutions) = calloc(n+1, sizeof(int**));
        //printf("(*solutions)=%p\n", solutions);
    }
    if(!(*solutions)[rootIdx]){
        (*solutions)[rootIdx] = calloc(n+1, sizeof(int*));
        //printf("(*solutions)[rootIdx]=%p\n", (*solutions)[rootIdx]);    
    }
    if(!(*solutions)[rootIdx][start]){
        (*solutions)[rootIdx][start] = calloc(n+1, sizeof(int));
        //printf("(*solutions)[rootIdx][start]=%p\n", (*solutions)[rootIdx][start]);
    }
    (*solutions)[rootIdx][start][end] = ret;
	
	
	//printf("ret = %d\n", left * right);
	return ret;
}

int numTrees(int n){
    int ***solutions=NULL;
    
    int ret = combinations(n, &solutions, n, 0, n);
    
    //free solutions
    if(solutions){
        for(int i=0; i<n; i++){
            if(solutions[i]){
                for(int j=0; j<n; j++){
                    if(solutions[i][j]){
                        free(solutions[i][j]);
                    }
                }
                free(solutions[i]);
            }
        }
        free(solutions);
    }
    
    
	//put all nums to left, so rootIdx = n
	return ret;
}

