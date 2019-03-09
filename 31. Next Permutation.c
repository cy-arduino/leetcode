int cmpfunc(const void* a, const void* b){
    int x,y;
    
    memcpy(&x, a, sizeof(int));
    memcpy(&y, b, sizeof(int));
    
    return (x-y);    
}

void swap(int* nums, int i, int j){
    nums[i]^=nums[j];
    nums[j]^=nums[i];
    nums[i]^=nums[j];
}

void dumpArr(int* nums, int numsSize){
    int i;
    
    printf("ARRAY: ");
    for(i=0; i<numsSize; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void nextPermutation(int* nums, int numsSize) {
    int max=-1, max_idx;
    int min=-1, min_idx;
    int i;
    
    for(i=numsSize-1; i>=0; i--){
        if(nums[i] >= max){
            max = nums[i];
            max_idx = i;
        }else{
            break;
        }
    }
    //printf("max_idx=%d, max=%d\n", max_idx, max);
    
    
    if(max_idx==0){
        //sort nums
        qsort(nums, numsSize, sizeof(int), cmpfunc);
    }else{
        for(i=numsSize-1; i>=max_idx; i--){
            if(nums[i] > nums[max_idx-1] && (min==-1 || min > nums[i])){
                min = nums[i];
                min_idx = i;
            }
        }        
        //printf("min_idx=%d, min=%d\n", min_idx, min);
        dumpArr(nums, numsSize);
        //swap nums[max_idx-1] & nums[min]
        swap(nums, max_idx-1, min_idx);
        
        //dumpArr(nums, numsSize);
        
        //sort
        qsort(nums+max_idx, numsSize-max_idx, sizeof(int), cmpfunc);
        
        //dumpArr(nums, numsSize);
    }
    
}
