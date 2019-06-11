/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode *newHead;
    struct ListNode *tmp, *tmp2;
    int listSize;
    
    if(k==0 || head==NULL)
        return head;
    
    //make circle && count listSize
    tmp = head;
    listSize=1;
    while(tmp->next!=NULL){
        tmp = tmp->next;
        listSize++;
    }
    tmp->next = head;
    
    //found new head
    tmp = head;
    k=k%listSize;
    while(listSize-- - k>0){
        tmp = tmp->next;
    }
    newHead = tmp;
    
    //break circle
    while(tmp->next!=newHead){
        tmp=tmp->next;
    }
    tmp->next=NULL;
    
    
    return newHead;
}

