/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    int * ret = NULL;
    
    //if(numsSize<2)
    //    goto out;
    
    ret = (int*) malloc(sizeof(int*) * 2);
    //if(!ret)
    //    goto out;
    
    //ret[0]=ret[1] =0;
    for(i = 0; i < numsSize; i++){
        for(j = i+1; j < numsSize; j++){
            if(nums[i]+nums[j] == target){
                ret[0] = i;
                ret[1] = j;
            }
        }        
    }

//out:
    return ret;
}