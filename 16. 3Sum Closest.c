 #include <limits.h>

int comp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

void dump(int *nums, int numsSize){
    printf("dump: ");
    for(int i=0; i<numsSize; i++){
        printf("%d, ", nums[i]);
    }
    printf("\n");
}

int threeSumClosest(int* nums, int numsSize, int target){

    //sort nums first
    qsort(nums, numsSize, sizeof(int), comp);
    //dump(nums, numsSize);
    
    int closest = nums[0]+nums[1]+nums[2] - target;
    int i,l,r,diff;
    for(i=0; i<numsSize-2; i++){
        l=i+1;
        r=numsSize-1;
        
        while(l<r){
            diff = nums[i]+nums[l]+nums[r] - target;
            //printf("%d,%d,%d diff=%d\n", i, l, r, diff);
            if((diff*diff)<(closest*closest)){//compare abs diff
                closest = diff;
            }
            //printf("closest=%d\n",closest);
            
            if(diff<0){
                l++;
            }else if(diff>0){
                r--;
            }else{
                //found the best solution
                break;
            }
        }
        
    }
    
    return closest+target;
}

