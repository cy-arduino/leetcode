/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


#define DefaultBufMaxLen 10
#define DefaultRetMaxLen 100

struct IntBuf{
    int *buf;
    int len;
    int maxLen;
};

struct IntBuf intBufGen(){
    struct IntBuf ret;
    ret.maxLen = DefaultBufMaxLen;
    ret.buf = malloc(ret.maxLen * sizeof(int));
    ret.len = 0;
    
    return ret;
}

void intBufDump(struct IntBuf *b){
    printf("DUMP: len=%d, maxLen=%d, buf=", b->len, b->maxLen);
    if(b->len==0){
        printf("empty");
    }
    for(int i=0; i<b->len; i++){
        printf("%d ", b->buf[i]);
    }
    printf("\n");
}

void intBufPush(struct IntBuf *b, int i){
    if(b->len+1 == b->maxLen){
        b->maxLen *=2;
        int *newBuf = realloc(b->buf, b->maxLen * sizeof(int));
        if(!newBuf){
            printf("%s: ERROR: realloc IntBuf\n");
            return;
        }
        b->buf = newBuf;
    }
    
    b->buf[(b->len)++] = i;
    
}

int intBufPop(struct IntBuf *b){
    if(b->len >0){
        b->len -=1;
        return b->buf[b->len];
    }else{
        printf("%s: ERROR: pop from empty buf!\n", __func__);
        return -1;
    }
}


void intBufDestroy(struct IntBuf *b){
    if(b->buf){
        free(b->buf);
    }
}
////////////////////////////

struct Ret{
    int **buf;
    int bufSize;
    int maxBufSize;
    int *colSizes;
};

struct Ret retGen(){
    struct Ret r;
    
    r.bufSize=0;
    r.maxBufSize = DefaultBufMaxLen;
    r.buf = malloc(r.maxBufSize * sizeof(int*));
    r.colSizes = malloc(r.maxBufSize * sizeof(int));
    
    return r;
}

void retAppend(struct Ret *r, int* buf, int bufLen){
    if(r->bufSize+1 == r->maxBufSize){
        r->maxBufSize *=2;
        
        int **newBuf = realloc(r->buf, r->maxBufSize * sizeof(int*));
        int *newColSizes = realloc(r->colSizes, r->maxBufSize * sizeof(int));
        if(!newBuf || ! newColSizes){
            printf("ERROR: realloc Ret\n");
        }
        
        r->buf = newBuf;
        r->colSizes = newColSizes;
    }
    
    r->buf[r->bufSize] = buf;
    r->colSizes[r->bufSize] = bufLen;
    r->bufSize ++;
}

void retDump(struct Ret *r){
    printf("RET: bufSize=%d, maxBufSize=%d \n", r->bufSize, r->maxBufSize);
}

void dfs(struct TreeNode* root, int sum, int curSum, struct IntBuf *curBuf, struct Ret *ret){
    //assume root is not NULL!
    if(!root)
        return;
    
    curSum += root->val;
    intBufPush(curBuf, root->val);
    
    //printf("\n%s: root->val=%d, sum=%d, curSum=%d\n",__func__, root->val, sum, curSum);
    //intBufDump(curBuf);
    
    //if a leaf
    if(!root->left && !root->right){

        //found a solution, copy to ret!
        if(curSum == sum){
            //printf("FOUND!\n");
            int *newBuf = malloc(curBuf->len * sizeof(int));
            for(int i=0; i<curBuf->len; i++){
                newBuf[i] = curBuf->buf[i];
            }
            retAppend(ret, newBuf, curBuf->len);

            //retDump(ret);
        }
    }else{
        if(root->left){
            dfs(root->left, sum, curSum, curBuf, ret);
        }
        if(root->right){
            dfs(root->right, sum, curSum, curBuf, ret);
        }

    }
    

OUT:
    intBufPop(curBuf);
    curSum -=root->val;
    
    return;
    
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    struct Ret ret = retGen();
    struct IntBuf curBuf = intBufGen();
    
    dfs(root, sum, 0, &curBuf, &ret);
    
    *returnSize = ret.bufSize;
    *returnColumnSizes = ret.colSizes;
    
    //retDump(&ret);
    
    return ret.buf;
}

