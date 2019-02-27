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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* A = l1;
    struct ListNode* B = l2;
    struct ListNode* ret = NULL;
    struct ListNode* new = NULL;
    struct ListNode* prev = NULL;
    
    int overflow = 0;
    int sum = 0;
    int first = 1;
    while(A!=NULL || B!=NULL || overflow>0 || first>0){
        //printf("in, A=%x, B=%x\n", A, B);
        if(first) first = 0;
        sum = 0;
        
        sum +=overflow;
        
        if(A){
            sum+=A->val;
            A = A->next;
        }
        
        if(B){
            sum+=B->val;
            B = B->next;
        }
        
        overflow = sum/10;
        sum = sum%10;
        //printf("sum=%d, overflow=%d\n", sum, overflow);
        
        new = (struct ListNode *) malloc(sizeof(struct ListNode));
        new->val = sum;
        new->next = NULL;
        
        if(!ret)
            ret = prev = new;
        else{
            prev->next = new;
            prev = new;
        }
        //printf("A=%x, B=%x, ret=%x, ret->next=%x, overflow = %d, first = %d\n", A, B, ret, ret->next, overflow, first);
    }
    printf("ret!");
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