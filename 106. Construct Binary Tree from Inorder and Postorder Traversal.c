/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode * getNode(){
    return calloc(1, sizeof(struct TreeNode));
}

void dump(char *name, int *data, int dataLen){
    printf("%s: ", name);
    for(int i=0; i<dataLen; i++){
        printf("%d\t", data[i]);
    }
    printf("\n");
}

struct TreeNode * getRoot(int* inorder, int inorderSize, int* postorder, int postorderSize){
    struct TreeNode *root = NULL;
    
    //dump("inorder", inorder, inorderSize);
    //dump("postorder", postorder, postorderSize);
    
    if(inorderSize<=0){
        return root;
    }
    
    //root is the last one in postorder
    root = getNode();
    root->val = postorder[postorderSize-1];
    
    if(inorderSize==1){
        return root;
    }
    
    //get root idx
    int i=0;
    for(i=0; i<inorderSize; i++){
        if(inorder[i] == root->val){
            break;
        }
    }
    
    //left
    root->left = getRoot(inorder, i, postorder, i);
    
    //if(inorderSize>=2)
    
    //right
    root->right = getRoot(inorder+i+1, inorderSize-i-1, postorder+i, postorderSize-i-1);
    
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if(!inorderSize || inorderSize!=postorderSize){
        printf("invalid input!\n");
    }
    
    dump(">inorder", inorder, inorderSize);
    dump(">postorder", postorder, postorderSize);
    
    return getRoot(inorder, inorderSize, postorder, postorderSize);
}

