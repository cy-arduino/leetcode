/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int *buf;
int bufLen;

void recursive(int start, int end, struct TreeNode **root){
    if(start > end){
        //special case
        *root=NULL;
        return;
    }
    
    int rootIdx = start +(end-start)/2 + (end-start)%2;
    
    
    *root = malloc(sizeof(struct TreeNode));
    (*root)->val = buf[rootIdx];
    recursive(start, rootIdx-1, &((*root)->left));
    recursive(rootIdx+1, end , &((*root)->right));
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    struct TreeNode *root=NULL;
    
    struct ListNode *iter = head;
    int listSize = 0;
    while(iter){
        listSize++;
        iter = iter->next;
    }
    
    //list to buf
    iter = head;
    buf = malloc(listSize * sizeof(int));
    for(int i=0; i<listSize; i++){
        buf[i] = iter->val;
        iter = iter->next;
    }
    
    
    recursive(0, listSize-1, &root);
    
    return root;

}

