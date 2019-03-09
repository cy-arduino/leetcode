int divide(int dividend, int divisor) {
    bool postive = true;
    long mDividend = (long)dividend;
    long mDivisor = (long)divisor;

    //to postive
    if(mDividend < 0){
        postive = !postive;
        mDividend = 0-mDividend;
    }
    if(mDivisor < 0){
        postive = !postive;
        mDivisor = 0-mDivisor;
    }

    long ret = 0;
    while(mDividend >= mDivisor){
        long quotient_add = 1;
        long tmp = mDivisor;
        while(mDividend >= tmp<<1){
            quotient_add += quotient_add;
            tmp<<=1;
        }
        ret += quotient_add;
        mDividend -= tmp;
    }

    if(!postive)
        ret = 0-ret;

    //check overflow
    if(ret > 2147483647)
        ret = 2147483647;
  

    return ret;
}
