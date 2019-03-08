int removeDuplicates(int* nums, int numsSize) {
    if(numsSize==0)
        return 0;
    
    int ret=1;
    int c = nums[0];

    for(int i=0; i<numsSize; i++){
        #printf("nums[%d]=%d\n", i, nums[i]);
        if(nums[i] != c){
            #printf("found!\n");
            c = nums[i];
            ret+=1;
            nums[ret-1] = c;
        }
    }    
    
    #printf("ret=%d\n", ret);
    
    return ret;
}
