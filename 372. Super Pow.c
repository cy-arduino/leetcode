
int my_pow(int a, int b){
    if(b < 0){
        //error
        exit(-1);
    }
    if(b == 0){
        // a^0 is 1
        return 1;
    }
    a %= 1337;
    
    int ret = 1;
    for(int i=1; i<=b; i++){
        ret = (ret*a) % 1337;
    }
    
    return ret;
}

int superPow(int a, int* b, int bSize){
    int ret = 1;
    for(int i=0; i<bSize; i++){
        int cur_num = my_pow(a, b[i]);
        int ten_power = bSize - i - 1;
        for (int j=0; j<ten_power; j++){
            cur_num = my_pow(cur_num, 10);
        }
        
        ret = (ret * cur_num) % 1337;
    }
    
    return ret;
}

