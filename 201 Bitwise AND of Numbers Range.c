/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
*/
#include <stdio.h>
#include <stdlib.h>

int rangeBitwiseAnd(int m, int n){

    int ret = m;
    for(int i=m; i<n; i++){
        // speedup 1: 
        //    2147483647 is 0x01111111111111111111111111111111(max positive int value in 32-bit int)
        //    i & i^2147483647 is 0. if i^2147483647 in range, result must be 0
        if((i^2147483647)>i && (i^2147483647) <=n){
            ret = 0;
            return ret;
        }

        ret&=i;
        // speedup 2: 
        //    0 & anything is 0
        if(!ret){
            return ret;
        }
    }
    ret&=n;
    return ret;
}

int main(void){

    printf("%d\n", rangeBitwiseAnd(0, 2147483647));

    return 0;
}