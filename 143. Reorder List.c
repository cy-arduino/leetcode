/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct myListNode {
    struct ListNode *data;
    struct myListNode *next;
};

void reorderList(struct ListNode* head){
    struct myListNode *revert = NULL;
    
    //build revert list
    struct ListNode *n = head;
    while(n){
        struct myListNode *myNode = calloc(1, sizeof(struct myListNode));
        myNode->data = n;
        myNode->next = revert;
        revert = myNode;
        
        n=n->next;
    }
    
    if(head){
        struct ListNode *n = head;
        while(n){
            //odd finish
            if(n==revert->data){
                n->next = NULL;
                break;
            }
            
            //even finish
            if(n->next==revert->data){
                n->next->next = NULL;
                break;
            }
            
            revert->data->next = n->next;
            n->next = revert->data;
            
            n=n->next->next;
            struct myListNode *toDel = revert;
            revert = revert->next;
            free(toDel);
        }
    }
        
        
    return head;
}

