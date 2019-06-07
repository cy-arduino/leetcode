#include <math.h>

int myAtoi(char * str){
    int sign=1;
    unsigned long long ret = 0;
    int started = 0;
    for(int i=0; i<strlen(str); i++){
        if(str[i]=='-' ||str[i]=='+'){
            if(started){
                printf("error 1: got '-' after start");
                break;
            }
            started = 1;
            
            if(str[i]=='-')
                sign=-1;
        }else if(str[i] >= '0' && str[i] <= '9'){
            if(!started)
                started = 1;               
            
            //printf("process %c\n", str[i]);
            ret *= 10;
            ret += (long)str[i]-'0';
            
            if(sign==1 && ret > pow(2,31)-1){
                ret = pow(2,31)-1;
                printf("overflow1 ret=%ld\n", ret);
                break;
            }
            if(sign==-1 && ret > pow(2,31)){
                ret = pow(2,31);
                printf("overflow2 ret=%ld\n", ret);
                break;
            }
        }else if(str[i]==' '){
            if(started)
                break;
        }else{
            break;
        }
        
    }
    return (int)(ret*sign);
}

