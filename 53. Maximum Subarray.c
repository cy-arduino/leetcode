int maxSubArray(int* nums, int numsSize) {
    int* sums;
    sums = (int*) malloc(sizeof(int)*numsSize);
    
    for(int i=0; i<numsSize; i++){
        sums[i]=((i>0)?sums[i-1]:0)+nums[i];
    }
    
    int max = 0;
    int base = 0;
    
    for(int i=0; i<numsSize; i++){
        //printf("sums[%d]=%d\n", i, sums[i]);
        
        if(i==0 || max < (sums[i]-base)){
            max = sums[i]-base;
        }
           
        if(base > sums[i]){
            base = sums[i];
        }   
        
    }
    
    
    return max;
}
