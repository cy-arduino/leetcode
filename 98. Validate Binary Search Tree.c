/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define DBG 0

//use min and max to limit subtree's regin
myIsValidBst(struct TreeNode *root, int *min, int *max){
#if DBG
    printf("%s: root=%d, left=%d, right=%d, min=%d, max=%d\n", 
           __func__,
           root?root->val:-1, 
          (root && root->left)?root->left->val:-1, 
          (root && root->right)?root->right->val:-1,
          (min)?*min:-1, 
          (max)?*max:-1);
#endif
    
    if(root){
        if(min && root->val <= *min){
            return false;
        }
        
        if(max && root->val >= *max){
            return false;
        }
        
        
        //check left sub-tree if exist
        if(root->left && !myIsValidBst(root->left, min, &(root->val)) ){
            return false;
        }
        
        //check right sub-tree if exist
        if(root->right && !myIsValidBst(root->right, &(root->val), max) ){
            return false;
        }
    }
    
    return true;
}

bool isValidBST(struct TreeNode* root){
    return myIsValidBst(root, NULL, NULL);
}

