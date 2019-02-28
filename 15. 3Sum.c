#define MY_ANS2 1

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int** threeSum(int* nums, int numsSize, int* returnSize){
    int i,j,k;
    int l,r;
    int sum;
    int **ret=NULL;
    ret = (int**) malloc(sizeof(int*) *20000);//TODO: use realloc
    
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    returnSize[0]=0;

    for(i=0; i<numsSize-2; i++){
        if(i>0 && nums[i]==nums[i-1])
            continue;        
        
        l=i+1;
        r=numsSize-1;
        
        while(l<r){
            //printf("[%d, %d, %d]: %d, %d, %d\n", i, l, r, nums[i],nums[l],nums[r]);
            sum = nums[i]+nums[l]+nums[r];
            if(sum<0){
                l++;
            }else if(sum>0){
                r--;
            }else{
                //found
                //printf("found! %d", returnSize[0]+1);
                
                ret[returnSize[0]]=(int*)malloc(sizeof(int)*3);
                ret[returnSize[0]][0]=nums[i];
                ret[returnSize[0]][1]=nums[l];
                ret[returnSize[0]][2]=nums[r];
                returnSize[0]++;
                
                while(nums[l+1]==nums[l]){
                    l++;
                }
                l++;
            }
        }
    }
    
    return ret;
}
