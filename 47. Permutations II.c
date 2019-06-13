int allocSize = 10000;

int comp(void *a, void *b){
    return *((int*)a) - *((int*)b);
}

void dump(int *n, int size, char *str){
    printf("%s: ", str);
    for(int i=0; i<size; i++){
        printf("%d ", n[i]);
    }
    printf("\n");
}


void gen(int* nums, int numsSize, int**ret, int* returnSize, int* returnColumnSizes, int *buf, int bufSize){
    //printf("\ngen()\n");
    //dump(nums, numsSize, "nums\t");
    //dump(buf, bufSize, "buf\t");
    
    if(numsSize>0){
        for(int i=0; i<numsSize; i++){
            //get non-repeat nums[i]
            if(i>0 && nums[i-1] == nums[i]){
                continue;
            }
            

            //add nums[i] to buffer
            buf[bufSize] = nums[i];
            bufSize++; 
            
            //back nums[i] into tmp and remove it from nums
            int tmp = nums[i];
            for(int idx=i; idx<numsSize-1; idx++){
                nums[idx] = nums[idx+1];
            }
            
            //recursive
            gen(nums, numsSize-1, ret, returnSize, returnColumnSizes, buf, bufSize);
            
            
            //insert tmp into nums[i]
            for(int idx=numsSize-1-1; idx>=i; idx--){
                nums[idx+1] = nums[idx];
            }
            nums[i] = tmp;
            
            //remove nums[i] from buffer
            bufSize--;
        }
    }else if(numsSize==0){
        //printf("found!\n");
        //dump(nums, numsSize, "nums\t");
        //dump(buf, bufSize, "buf\t");
        int* newElem = malloc(bufSize * sizeof(int));
        
        for(int i=0; i<bufSize; i++){
            newElem[i]=buf[i];
        }
        
        //realloc if need
        if((*returnSize)+1>=allocSize){
            allocSize*=2;
            ret = realloc(ret, allocSize*sizeof(int*));
			returnColumnSizes = realloc(returnColumnSizes, allocSize * sizeof(int));
        }
        ret[(*returnSize)]=newElem;
        returnColumnSizes[(*returnSize)]=bufSize;
        (*returnSize)++;
    }else{
        printf("Error!\n");
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ret = malloc(allocSize * sizeof(int*));
    (*returnColumnSizes) = malloc(allocSize * sizeof(int));
    (*returnSize) = 0;
    
    //sort nums
    qsort(nums, numsSize, sizeof(int), comp);
    
    dump(nums, numsSize, "sorted nums");
    
    int *buf = malloc(numsSize * sizeof(int));
    int bufSize = 0;
    
    gen(nums, numsSize, ret, returnSize, (*returnColumnSizes), buf, bufSize);
    
    free(buf);
    
    return ret;
}

