
//Tip: XOR
//any date XOR self is 0x0
//any data XOR 0x0 is the data itself
int singleNumber(int* nums, int numsSize){
    if(numsSize <=0){
        //TODO: error
        return -1;
    }
    
    if(numsSize == 1){
        return nums[0];
    }
    
    int ret = nums[0];
    
    for(int i=1; i<numsSize; i++){
        ret ^= nums[i];
    }
    
    return ret;
}

