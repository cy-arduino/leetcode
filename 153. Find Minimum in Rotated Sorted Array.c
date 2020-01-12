
int getMin(int *nums, int left, int right){
    printf("l: %d, r: %d\n", left, right);
    
    if(left >= right){
        //TODO: handle error
        return -1;
    }
    
    //finally(two number)
    if(left+1==right){
        if(nums[left]<nums[right]){
            return nums[left];
        }else{
            return nums[right];
        }
    }
    
    //left is the smallist, return directly
    if(nums[left]<nums[right]){
        return nums[left];
    }
    
    //otherwise, do binary search
    int mid = (left+right)/2;
    if(nums[mid] < nums[left]){
        //left side
        return getMin(nums, left, mid);
    }else{
        //right side
        return getMin(nums, mid, right);
    }
}


int findMin(int* nums, int numsSize){
	//TODO: remove duplicate
	//TODO: shift to remove negative number so that -1 means something wrong
	
    if(!nums || numsSize == 0){
        //TODO: how to handle error?
        return -1;
    }
    
    if(numsSize == 1){
        return nums[0];
    }    
    
    return getMin(nums, 0, numsSize-1);
}

