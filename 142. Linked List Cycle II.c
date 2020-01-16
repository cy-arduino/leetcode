/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MY_LIST_INIT_SIZE 100
#define MY_LIST_INC_SIZE 10
typedef struct myList{
    int size;
    int maxSize;
    struct ListNode **data;
}mylist;

mylist * myListGen(){
    mylist *l = malloc(1*sizeof(mylist));
    l->size = 0;
    l->maxSize = MY_LIST_INIT_SIZE;
    l->data = malloc(MY_LIST_INIT_SIZE * sizeof(struct ListNode*));
    
    return l;
}

void myListDestroy(mylist *l){
    if(l){
        if(l->data){
            free(l->data);
        }
        free(l);
    }
}

void myListPush(mylist *l, struct ListNode *data){
    if(l){
        //todo: increase maxSize if need
        if(l->size>=l->maxSize){
            struct ListNode **newData = realloc(l->data, (l->size+MY_LIST_INC_SIZE)*sizeof(struct ListNode *));
            if(!newData){
                //todo: handle it
                printf("OOM\n");
                return;
            }
            l->data = newData;
        }
        
        l->data[l->size++] = data;
    }
}

bool myListExist(mylist *l, struct ListNode *data){
    //todo: use binary search to speedup
    for(int i=0; i<l->size; i++){
        if(l->data[i]==data){
            return true;
        }
    }
    return false;
}


struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *n = head;
    struct ListNode *ret = NULL;
    mylist *l = myListGen();
    
    while(n){
        if(myListExist(l, n)){
            ret = n;
            break;
        }else{
            myListPush(l, n);
            n = n->next;
        }
    }
    myListDestroy(l);
    return ret;
}