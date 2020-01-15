/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define ARR_INIT_SIZE 100
#define ARR_INC_SIZE 10
typedef struct IntArray{
    int size;
    int maxSize;
    int *data;
}intArr;

intArr * arrGen(){
    intArr *arr = malloc(sizeof(intArr));
    arr->size = 0;
    arr->maxSize = ARR_INIT_SIZE;
    arr->data = malloc(arr->maxSize * sizeof(int));
    //TODO: handle oom
    return arr;
}

//TODO: handle error
void arrAppend(intArr *arr, int data){
    if(arr){
        //todo expend arr if need
        
        arr->data[arr->size++] = data;
    }
}

void postorder(struct TreeNode* root, intArr *result){
    if(root){
        postorder(root->left, result);
        postorder(root->right, result);
        arrAppend(result, root->val);
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* ret = NULL;
    
    *returnSize = 0;
    
    intArr *result = arrGen();
    postorder(root, result);
    
    *returnSize = result->size;
    ret = result->data;
    
    free(result);
    
    return ret;
}

