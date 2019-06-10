double myPow(double x, int n){
    if(n==0)
        return (double)1;
    
    double mN = (double)n;
    double ret=1;
    int positive = (mN<0)?0:1;

    if(mN < 0){
        mN = -1* mN;
    }

#if 0
    //too slow!
    for(int i=0; i<mN; i++){
        ret=ret*x;
    }
#else
	//3^9 = (3^8) * 3^1 
	//3^8 = (((3^1)^2)^2)^2
    double i=1;
    double tmp=x;
    while(i*2<=mN){
        tmp = tmp*tmp;
        i=i*2;
    }
    if((mN-i)>0){
        tmp = tmp * myPow(x,mN-(int)i);
    }
    
    ret = tmp;
#endif
    
    if(!positive){
        ret = 1/ret;
    } 
    
    return ret;
}

