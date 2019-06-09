/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#if 0
//method 1
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
        //printf("remove head!\n");
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

#else

//method2
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *mIter = head;
    struct ListNode *ret = NULL;
    struct ListNode *toDel = NULL;
    struct ListNode *toDelPrev = head;
        
    //assume n always valid
    for(int i=0; i< n-1; i++){
        mIter = mIter->next;
    }
    
    if(mIter->next==NULL){
        //remove head;
        ret = head->next;
        toDel = head;
    }else{
        mIter = mIter->next;
        
        while(mIter->next){
            mIter = mIter->next;
            toDelPrev = toDelPrev->next;
        }
        //found
        toDel = toDelPrev->next;
        toDelPrev->next = toDel->next;
        ret = head;
    }
    
    if(toDel)
        free(toDel);
    
    return ret;
}
#endif