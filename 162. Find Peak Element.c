

int findPeakElement(int* nums, int numsSize){
    if (numsSize <=0){
        printf("invalid input\n");
        return -1;
    }
    
    int l = 0;
    int r = numsSize-1;
    int mid = (l+r)/2;
    
    while(r>l){
        if(nums[mid]>nums[mid+1]){
            r=mid;
        }else{
            l = mid +1;
        }
        mid = (l+r)/2;
    }
    
    return l;

}

