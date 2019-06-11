

bool canJump(int* nums, int numsSize){
    int cur=0;
    
    while(cur<numsSize && nums[cur]!=0){ //cannot keep going if nums[cur]==0
        //printf("check: cur=%d, numsSize=%d, nums[cur]=%d\n", cur, numsSize, nums[cur]);
        int next=cur+nums[cur];
        int maxDistance=0;
        for(int i=cur; i<((cur+nums[cur]<=numsSize)?cur+nums[cur]:numsSize) ; i++){
            //printf("i=%d, cur+nums[cur]=%d\n",i, (cur+nums[cur]<=numsSize)?cur+nums[cur]:numsSize);
            if(i+nums[i] > maxDistance){
                maxDistance = i+nums[i];
                next = i;
            }
        }
        if(next==cur){
            next=cur+nums[cur];
        }
        
        //printf("next=%d\n", next);
        cur = next;
    }
    
    if(cur < numsSize-1){
        return false;
    }else{
        return true;
    }

}

