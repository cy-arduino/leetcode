int lengthOfLIS(int* nums, int numsSize){
    int max_size = 0;
    int *saved_size = (int *) calloc(numsSize, sizeof(int)); //default size is 0 because calloc
    
    for(int i=0; i<numsSize; i++){
        int size = get_inc_size(nums, numsSize, i, saved_size);
        if(size > max_size)
            max_size = size;
    }
    
    free(saved_size);
    
    return max_size;
}

int get_inc_size(int *nums, int numsSize, int start_idx, int *saved_size){
    if(saved_size[start_idx]){
        //printf("get_inc_size, start is #%d %d, ret is %d from saved_data\n", start_idx, nums[start_idx], saved_size[start_idx]);
        return saved_size[start_idx];
    }
    
    int max_next_inc_size = 0;
    for(int i=start_idx+1; i<numsSize; i++){
        if(nums[i] > nums[start_idx]){
            int next_len = get_inc_size(nums, numsSize, i, saved_size);
            if(next_len > max_next_inc_size){
                max_next_inc_size = next_len;
            }
        }else{
            continue;
        }
    }
    max_next_inc_size += 1; //add self
    //printf("get_inc_size, start is #%d %d, ret is %d\n", start_idx, nums[start_idx], max_next_inc_size);

    //DP
    saved_size[start_idx] = max_next_inc_size;

    return max_next_inc_size;
}

