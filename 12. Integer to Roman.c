char * intToRoman(int num){
    char *ret=(char*) calloc(sizeof(char),100);
    int retIdx = 0;
    
    int k=0;
    
    k=num/1000;
    //printf("1000, k=%d\n", k);
    for(int i=k; i>0; i--){
        ret[retIdx++]='M';
    }
    num = num%1000;
    
    k=num/100;
    //printf("100, k=%d\n", k);
    if(k<4){
        for(int i=k; i>0; i--){
            ret[retIdx++]='C';
        }
    }else if(k==4){
        ret[retIdx++]='C';
        ret[retIdx++]='D';
    }else if(k<9){
        ret[retIdx++]='D';
        for(int i=k-5; i>0; i--)
            ret[retIdx++]='C';
    }else if(k==9){
        ret[retIdx++]='C';
        ret[retIdx++]='M';
    }        
    num = num%100;
    
    k=num/10;
    //printf("10, k=%d\n", k);
    if(k<4){
        for(int i=k; i>0; i--){
            ret[retIdx++]='X';
        }
    }else if(k==4){
        ret[retIdx++]='X';
        ret[retIdx++]='L';
    }else if(k<9){
        ret[retIdx++]='L';
        for(int i=k-5; i>0; i--)
            ret[retIdx++]='X';
    }else if(k==9){
        ret[retIdx++]='X';
        ret[retIdx++]='C';
    }        
    num = num%10;
    
    k=num;
    //printf("0, k=%d\n", k);
    if(k<4){
        for(int i=k; i>0; i--){
            ret[retIdx++]='I';            
        }
    }else if(k==4){
        ret[retIdx++]='I';
        ret[retIdx++]='V';
    }else if(k<9){
        ret[retIdx++]='V';
        for(int i=k-5; i>0; i--)
            ret[retIdx++]='I';
    }else if(k==9){
        ret[retIdx++]='I';
        ret[retIdx++]='X';
    }        
    
    //printf("ret = %s, retIdx=%d", ret, retIdx);
    
    return ret;
}

