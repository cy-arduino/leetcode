/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void dump(struct ListNode* head){
    printf("dump: ");
    while(head){
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode tmp;
    struct ListNode *myHead = &tmp;
    myHead->next = head;
    myHead->val = -1;
    
    //find insert point and remove point
    struct ListNode *iter = myHead;
    for(int i=0; i<m-1; i++){
        iter = iter->next;
    }  
    struct ListNode *insPrev = iter;
    struct ListNode *rmPrev = iter->next;
    
    //printf("insPrev=%d, rmPrev=%d, m=%d, n=%d\n", insPrev->val, rmPrev->val, m, n);
    
	//move (n-m) nodes from remove point to insert point
    for(int i=0; i<(n-m); i++){
        //remove a node
        struct ListNode *toRm = rmPrev->next;
        rmPrev->next = toRm->next;
        
        //printf("after remove: ");
        //dump(myHead);
        
        //insert removed node
        toRm->next = insPrev->next;
        insPrev->next = toRm;
        
        //printf("after insert: ");
        //dump(myHead);
    }
    
    return myHead->next;
    
}

