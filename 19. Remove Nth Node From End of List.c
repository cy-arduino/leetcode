/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int nextIdx(int i, int n){
    i++;
    if(i==n)
        i=0;
    return i;
}

int prevIdx(int i, int n){
    i--;
    if(i<0)
        i=n;
    return i;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int bufSize = n+1;
    struct ListNode **buf = calloc(bufSize, sizeof(struct ListNode*));
    
    struct ListNode* mListIter= head;
    int i=0;
    while(mListIter != NULL){
        buf[i] = mListIter;
        i = nextIdx(i, bufSize);
        mListIter = mListIter->next;
    }
    
    struct ListNode *ret = NULL;
    struct ListNode *toDel = NULL;
    if(buf[i]==NULL){
        //remove head
        printf("remove head!\n");
        toDel = head;
        ret = head->next;
    }else{
        ret = head;
        toDel = buf[i]->next;
        buf[i]->next = toDel->next;
    }
    /*
    for(int k=0; k<bufSize; k++){
        printf("%d, ",(buf[k])?buf[k]->val:-1);
    }
    printf("\n");
    printf("toDel = %d, i=%d\n", toDel->val, i);
    */
    
    if(toDel)
        free(toDel);
    
    return ret;
    
}

