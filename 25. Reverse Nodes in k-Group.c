
//assume k=3
//before:
//   framePrev-->1-->2-->3(nextFramePrev)-->frameNext
//after:
//   framePrev-->3-->2-->1(nextFramePrev)-->frameNext
//return: nextFramePrev
struct ListNode* reverseFrame(struct ListNode* framePrev, int k, struct ListNode** nodes){
    struct ListNode* frameNext;
    struct ListNode* T;
    struct ListNode* T2;
    int i;
    
    //printf("%s: framePrev=%x, k=%d\n", __func__, framePrev, k);

    //error check
    if(!framePrev){
        printf("%s: framePrev is null\n", __func__);
        return NULL;
    }
    if(k<2){
        printf("%s: k<2\n", __func__);
        return NULL;
    }

    //put whole frame into nodes
    T=framePrev;
    for(i=0; i<k; i++){
        if(!T || !T->next){
            printf("%s: frame is not complete\n", __func__);
            return NULL;
        }
        T=T->next;
        
        nodes[i] = T;
    }
    frameNext=T->next;
    
    //rebuild frame
    T=framePrev;
    for(i=k-1; i>=0; i--){
        T->next = nodes[i];
        T=T->next;
    }
    T->next=frameNext;
    
    return T;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *T;
    struct ListNode *myHead;
    struct ListNode** nodes;
        
    myHead = (struct ListNode*) calloc(1, sizeof(struct ListNode));
    if(!myHead){
        printf("%s: myHead: out of mamory\n", __func__);
        return NULL;
    }
    
    nodes = (struct ListNode**) calloc(k, sizeof(struct ListNode*));
    if(!nodes){
        printf("%s: nodes: out of mamory\n", __func__);
        return NULL;
    }
    
    T=myHead;
    T->next = head;
    
    while(T && (T=reverseFrame(T,k, nodes)) !=NULL){
    }
    
    return myHead->next;
}
