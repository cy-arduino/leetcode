int swapBit(int n, int idx){
    return n^(1<<idx);
}


/*
tip:
    n=1, bit 0 flip
        0
        1
    n=2, copy n=1 in reverse order and add bit2=1
         0
         1
        11
        10
    n=3
         00
         01
         11
         10
        110
        111
        101
        100
*/
void gen(int *ret, int n){
    if(n==0){
        ret[0]=0;
        ret[1]=1;
    }else{
        int bit = n;
        int copyNum = pow(2, n);
        
        for(int i=0; i<copyNum; i++){
            ret[copyNum+i]=ret[copyNum-i-1] | 1<<bit;
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    *returnSize=0;
    int maxRetSize = pow(2, n);
    printf("maxRetSize=%d\n", maxRetSize); 
    
    int *ret = calloc(maxRetSize, sizeof(int));
    
    for(int i=0; i<n; i++){
        gen(ret, i);
    }
    
    *returnSize = maxRetSize;
    
    return ret;
}
