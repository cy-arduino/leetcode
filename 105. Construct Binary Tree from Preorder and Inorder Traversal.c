/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
 
/*
 My concept:
 
 tree:
				4
		2				6
	1		3		5		7
	
 preorder: 4213657
 inorder : 1234567
 
 #recursive 1
 root = preorder[0] = 4
 left
	preorder: 213 <==same size of inorder
	inorder : 123 <==left of root in inorder
 right
	preorder: 657
	inorder : 567

 #recursive 1.1
 root = 2
 left
	preorder: 1
	inorder : 1
 right
	preorder: 3
	inorder : 3
	
 #recursive 1.1.1
 root = 1
 left
	None
 right
	None
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

