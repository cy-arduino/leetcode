#define TRICK_FOR_SMALL_NUMBER 0
#define NORMAL 1

#if NORMAL
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ret=NULL,*retIter=NULL,*l1p=l1,*l2p=l2;
    
    int carry = 0;
    int partialSum = 0;
    
    while(l1p != NULL || l2p !=NULL){
        partialSum = ((l1p!=NULL)?(l1p->val):0) + ((l2p!=NULL)?(l2p->val):0) + carry;
        
        carry = partialSum / 10;
        partialSum = partialSum % 10;
               
        l1p = (l1p!=NULL)?(l1p->next):NULL;
        l2p = (l2p!=NULL)?(l2p->next):NULL;
        
        struct ListNode *newDigit = (struct ListNode *) malloc(sizeof(struct ListNode));
        newDigit->val = partialSum;
        newDigit->next = NULL;
        
        if(ret == NULL){
            ret = retIter = newDigit;
        }else{
            retIter->next = newDigit;
            retIter = retIter->next;
        }
        
        
    }
    if(carry > 0){
        struct ListNode *newDigit = (struct ListNode *)malloc(sizeof(struct ListNode));
        newDigit->val = carry;
        newDigit->next = NULL;
        
        retIter->next = newDigit;
        retIter = retIter->next;
    }
    
    return ret;
}
#endif


#if TRICK_FOR_SMALL_NUMBER
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    double a = 0;
    double b = 0;
    double sum;
    
    int mul;
    struct ListNode * T;
    struct ListNode * tmp;
    
    int mod;
    
    struct ListNode* ret = NULL;
    
    int first = 1;
    
    mul = 1;
    T=l1;
    while(T){
        a+=T->val * mul;
        mul*=10;
        T=T->next;
    }
    printf("a=%lf\n", a);
    
    mul = 1;
    T=l2;
    while(T){
        b+=T->val * mul;
        mul*=10;
        T=T->next;
    }
    printf("b=%lf\n", b);
    
    sum = a + b;
    printf("sum=%lf\n", sum);
    while(sum || first){
        if(first)
            first = 0;
        tmp = (struct ListNode*) malloc(sizeof(struct ListNode));
        tmp->val = sum - floor(sum/10)*10;
        tmp->next = NULL;
        sum=floor(sum/10)*10;
        
        if(ret == NULL){
            ret = T = tmp;
        }else{
            T->next = tmp;
            T = tmp;
        }
    }
    
    return ret;
    
}
#endif