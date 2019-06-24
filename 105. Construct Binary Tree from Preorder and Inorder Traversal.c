/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void recursive(int* preorder, int preorderSize, int* inorder, int inorderSize, struct TreeNode **pRoot){
    if(!preorderSize)
        return;
    
    *pRoot = malloc(sizeof(struct TreeNode));
    (*pRoot)->val = preorder[0];
    (*pRoot)->left = (*pRoot)->right = NULL;
    
    int leftSize;
    while(inorder[leftSize]!=preorder[0]){
        leftSize++;
    }
    
    if(leftSize>0){
        recursive(preorder+1, leftSize, inorder, leftSize, &((*pRoot)->left));
    }
    
    int rightSize = preorderSize - 1 - leftSize;
    if(rightSize > 0){
        recursive(preorder+1+leftSize, rightSize, inorder+leftSize+1, rightSize, &((*pRoot)->right));
    }

}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    struct TreeNode *root = NULL;
    
    
    recursive(preorder, preorderSize, inorder, inorderSize, &root);
    
    return root;
    
}

