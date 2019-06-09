#define SWAP(a,b) {char *tmp = a; a = b; b=tmp;}
\//assume strlen(buf) == strlen(n1) and enough
void mulInto(char *buf, char *n1, int m, int shift){
    int mul=0;
    int carry =0;
    
    int bufIdx = strlen(buf)-1-shift;
    int n1Idx = strlen(n1)-1;
    
    //printf("mul: n1=%s, m=%d, shift=%d\n", n1, m, shift);
    
    for(int i=n1Idx; i>=0; i--){
        mul = m*(n1[i]-'0')+carry;
        carry = mul/10;
        mul = mul%10;
        
        buf[bufIdx--] = '0' + mul;
    }
    
    if(carry)
        buf[bufIdx] = '0' + carry;
    
    //printf("mul: ret = %s\n", buf);
}

//assume strlen(n1) == strlen(n2) and the length is enough 
void addInto(char *n1, char *n2){
    
    //printf("add: n1=%s, n2=%s\n", n1, n2);
    int sum = 0;
    int carry = 0;
    for(int i=strlen(n1)-1; i>=0; i--){
        sum = n1[i]-'0' + n2[i]-'0' + carry;
        carry = sum/10;
        sum = sum %10;
        n1[i] = '0' + sum;
        //printf("i=%d, n1[i]=%d, sum=%d, carry=%d\n", i, n1[i], sum, carry);
    }
    //printf("add: ret=%s", n1);
}

char * multiply(char * num1, char * num2){
    
    char *ret = calloc((strlen(num1)+strlen(num2)+2),sizeof(char));
    for(int i=0; i<(strlen(num1)+strlen(num2)+1); i++){
        ret[i]='0';
    }
    
    char *buf = calloc((strlen(num1)+strlen(num2)+2),sizeof(char));
    
    
    //speedup
    if(strlen(num1)<strlen(num2)){
        SWAP(num1, num2);
    }
    
    
    printf("mul: n1=%s, n2=%s\n", num1, num2);
    
    for(int n2Idx=strlen(num2)-1; n2Idx>=0; n2Idx--){
        
        //clear buf
        for(int i=0; i<(strlen(num1)+strlen(num2)+1); i++){
            buf[i]='0';
        }
        
        
        
        mulInto(buf, num1, num2[n2Idx]-'0', strlen(num2)-1-n2Idx);
        addInto(ret, buf);
    }
    
    int i=0;
    for(i=0; i<strlen(ret)-1; i++){
        if(ret[i] !='0')
            break;
    }
    
    return ret+i;

}

