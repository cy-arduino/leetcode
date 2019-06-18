/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
//for debug
void dumpList(struct ListNode *head, char *str){
    printf("%s: ", str);
    while(head->next){
        printf("%d ", head->next->val);
        head = head->next;
    }
    printf("\n");
}

//use myHead to maintain head become NULL
struct ListNode* partition(struct ListNode* head, int x){
    
    
    struct ListNode tmp[2];
    struct ListNode *myHead = &(tmp[0]);
    myHead->next = head;
    myHead->val = -1;
	
    struct ListNode *delHead = &(tmp[1]);        
    delHead->next = NULL;
    
    struct ListNode *insPoint = NULL;
    
    struct ListNode *iter;
    struct ListNode *iter2;

	//delete Nodes that <x from myHead
    iter = myHead;
    while(iter && iter->next){
        if(iter->next->val <x){  
            struct ListNode *toDel = iter->next;    
            
            //delet toDel 
            iter->next = toDel->next;            
            
            //put toDel into delHead
            toDel->next = delHead->next;
            delHead->next = toDel;
            
        }else{
            iter = iter->next;
        }
    }
    
    //dumpList(myHead, "list");
    //dumpList(delHead, "deleted");
    
    //find the insert point
    insPoint = myHead;
    while(insPoint && insPoint->next){
        if(insPoint->next->val >= x){
            break;
        }
            
        insPoint = insPoint->next;
    }
    //printf("insert point=%d\n", insPoint->val);
        
	//insert Nodes from deleted into myHead
    iter2 = delHead;
    while(iter2->next){
        struct ListNode *toIns = iter2->next;
        
        //remove toIns from deleted
        iter2->next = toIns->next;
        
        //insert toIns into insert point
        toIns->next = insPoint->next;
        insPoint->next = toIns;
    }
    
    
    return myHead->next;    
}

