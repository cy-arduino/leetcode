#include <math.h>

//assume n > 0
double myPow2(double x, int n) {
    double ret=x;
    
    if(isinf(ret)){
        return ret;
    }
    
    
    if(n>1){
        
        ret=myPow2(x, n/2);
        
        if(isinf(ret)) goto out;
        
        ret*=ret;
        
        if(isinf(ret)) goto out;
        
        if(n%2){
            ret*=x;
        }
    }

out:
    return ret;
}

double myPow(double x, int n) {
    int i;
    double ret=INFINITY;
    int minus_n=0;
    
    double n2 = (double) n;
    
    printf("x=%lf, n=%d\n", x, n);
    
    
    //special case: x==1 or x==-1
    if(x==1)
        return 1;
    
    if(x==-1){
        if(n%2)
            return -1;
        else
            return 1;
    }
    
    //special case: x==0
    if(x==0)
        return 0;
    
    //special case: n out of range
    if(n2 >= 2147483648){
        printf("n out of range 1\n");
        return ret;
    }
    
    if(n2 <= -2147483648){
        printf("n out of range 2\n");
        return 0;
    }

    //special case: n==0
    if(n==0){
        printf("n==0\n");
        return 1;
    }
    
    if(n<0){
        n = n*-1;
        minus_n = 1;
    }
     
    ret = myPow2(x, n);

    if(minus_n){
        if(isinf(ret)){
            ret = 0;
        }else{
            ret = 1/ret;
        }
    }
    
    return ret;
}