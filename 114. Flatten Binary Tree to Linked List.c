/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode **newTreeInsPoint;

void recursive(struct TreeNode *root){
    if(!root)
        return;
    
    //printf("%d ", root->val);
    
    //add root into new tree
    struct TreeNode *newNode = calloc(1, sizeof(struct TreeNode));
    newNode->val = root->val;
    newNode->left = newNode->right = NULL;
    
    *newTreeInsPoint=newNode;
    
    newTreeInsPoint = &(newNode->right);
    
    
    //recursive
    if(root->left){
        recursive(root->left);
        free(root->left);
    }
    if(root->right){
        recursive(root->right);
        free(root->right);
    }

}

void flatten(struct TreeNode* root){
    if(!root)
        return;
    
    struct TreeNode *newRoot;
    newTreeInsPoint = &newRoot;
    
    recursive(root);
    
    root->left = NULL;
    root->right = newRoot->right;

}

