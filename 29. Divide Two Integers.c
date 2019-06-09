
int divide(int dividend, int divisor){
    //printf("dividend=%d, divisor=%d\n", dividend, divisor);

    int sign = 1;
    
    unsigned int newDividend, newDivisor;
    
    
    if( (dividend < 0 && divisor >=0) || (dividend >= 0 && divisor < 0) ){
        sign = -1;
    }
    
    if(dividend < 0){
        newDividend = (unsigned int)0-dividend;
    }else{
        newDividend = dividend;
    }
    if(divisor < 0){
        newDivisor = (unsigned int)0-divisor;
    }else{
        newDivisor = divisor;
    }
    
    printf("newDividend=%u, newDivisor=%u, sign=%d\n", newDividend, newDivisor, sign);

    unsigned int ret = 0;
    
    
#if 0 //timeout
    while(newDividend >= newDivisor){
        newDividend -= newDivisor;
        //printf("newDividend = %u\n", newDividend);
        ret ++;
    }
#else
	// example:
	// 16/3 = 5..1
	// 16 = 3*5 + 1
	//    = 3*(2^2 + 2^0) + 1
	//    = 3<<2 + 3<<0 + 1      <=====use shift to replace *
    unsigned long long tmp = 0;
    while(newDividend >= newDivisor){
        int i=0;
        while(newDivisor<<i < pow(2,31) && (newDivisor<<(i+1)) <= newDividend){
            i+=1;
        }
        tmp=newDivisor<<i;
        
        newDividend -=tmp;
        ret += pow(2,i);
    }
#endif
    
    if(sign == 1 && ret > pow(2,31)-1){
        ret = pow(2,31)-1;
    }
    if(sign == -1 && ret > pow(2,31)){
        ret = pow(2,31);
    }
    
    if(sign == -1){
        return (int)0-ret;
    }else{
        return (int)ret;
    }

    
}

