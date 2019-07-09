/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxRetSize = 100;


void recursive(struct TreeNode *root, int **ret, int *returnSize, int level){
    if(root){
        
        if(*returnSize < level+1){
            *returnSize = level+1;
            
            if(*returnSize > maxRetSize){
                maxRetSize *=2;
                printf("Realloc: %d\n", maxRetSize);
                *ret = realloc(*ret, maxRetSize * sizeof(int));
            }
        }
        (*ret)[level] = root->val;
        
        //left
        recursive(root->left, ret, returnSize, level+1);
        
        //right
        recursive(root->right, ret, returnSize, level+1);
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize){
    
    int *ret = calloc(maxRetSize, sizeof(int));
    *returnSize = 0;
    
    recursive(root, &ret, returnSize, 0);    
        
    return ret;

}

