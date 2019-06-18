/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int allocSize = 100;

int insert(int **ret, int *returnSize, int n){
    
    //realloc if need
    if(((*returnSize)+1) == allocSize){
        //realloc
        allocSize*=2;
        
        int *new = realloc((*ret), allocSize*sizeof(int));
        if(new)
            (*ret) = new;
        else{
            printf("ERROR: realloc");
            return -1;
        }
    }
    
    (*ret)[(*returnSize)++] = n;
    
    return 0;
}

void myTraversal(struct TreeNode *root, int **ret, int *returnSize){
    
    if(root){
        //left
        if(root->left){
            myTraversal(root->left, ret, returnSize);
        }
        
        //self
        insert(ret, returnSize, root->val);
        
        //right
        if(root->right){
            myTraversal(root->right, ret, returnSize);
        }
    }
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *ret = malloc(allocSize * sizeof(int));
    *returnSize = 0;
    
    myTraversal(root, &ret, returnSize);
    return ret;
}

