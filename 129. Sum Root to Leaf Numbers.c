/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int calculate(struct TreeNode* root, int prevSum){
    int curSum = prevSum*10 + root->val;
    //printf("root=%d, prevSum=%d, curSum=%d, left=%p, right = %p\n", root->val, prevSum, curSum, root->left, root->right);
    if(!root->left && !root->right){
        return curSum;
    }
    
    int sum = 0;
    if(root->left){
        sum += calculate(root->left, curSum);
    }
    if(root->right){
        sum += calculate(root->right, curSum);
    }
    return sum;
}

int sumNumbers(struct TreeNode* root){
    if(!root){
        printf("invalid input\n");
        return 0;
    }
    
    return calculate(root, 0);
}

