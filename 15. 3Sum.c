int comp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

/*
void dump(int *nums, int numsSize){
    printf("dump: ");
    for(int i=0; i<numsSize; i++){
        printf("%d, ", nums[i]);
    }
    printf("\n");
}*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//time complexity: O(n^2)
#define RET_SIZE_INC_STEP 50000
#define 
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    //first step: sort nums
    qsort(nums, numsSize, sizeof(int), comp);
    //dump(nums, numsSize);
    
    int maxReturnSize=RET_SIZE_INC_STEP;
    int **ret = (int**) calloc(maxReturnSize, sizeof(int*));    
    *returnColumnSizes = (int*) calloc(maxReturnSize, sizeof(int));
    returnSize[0]=0;
    
    for(int i=0; i<numsSize -2; i++){
        int l=i+1;
        int r=numsSize-1;        
        
        while(l<r){
            //printf(">> %d,%d,%d\n", i, l, r);
            if(nums[i]+nums[l]+nums[r]<0){
                //nums[l]+nums[r] must bigger
                l++;
                continue;
            }else if(nums[i]+nums[l]+nums[r] > 0){
                //nums[l]+nums[r] must smaller
                r--;
                continue;
            }else{
                //found solution
                //TODO: check if solution duplicat
                int duplicate = 0;
                for(int j=0; j<returnSize[0]; j++){
                    if(ret[j][0]==nums[i] && ret[j][1]==nums[l] && ret[j][2]==nums[r]){
                        //printf("duplicate\n");
                        duplicate = 1;
                        break;
                    }
                }
                if(!duplicate){
                    //printf("found\n");
                    int* solution = (int*) malloc(3*sizeof(int));
                    solution[0] = nums[i];
                    solution[1] = nums[l];
                    solution[2] = nums[r];

                    //TODO: increase ret and returnColumnSizes if need
                    if(returnSize[0]+1 >= maxReturnSize){
                        //printf("realloc\n");
                        maxReturnSize*=2;
                        ret = realloc(ret, maxReturnSize*sizeof(int*));
                        *returnColumnSizes = realloc(*returnColumnSizes, maxReturnSize*sizeof(int));
                    }

                    ret[returnSize[0]] = solution;

                    (*returnColumnSizes)[returnSize[0]] = 3;

                    returnSize[0]++;
                }
                //printf("returnSize=%d\n", returnSize[0]);
                l++;
                continue;
            }
        }
    }
    
    //printf("ret returnSize=%d", *returnSize);
    return (int**) ret;
}