/*char bitmap[128/8];//128bit = 16byte. bitmap for ascii

int exist(char c){
    return (bitmap[c/8]&(1<<c%8)) > 0;
}

void put(char c){
    bitmap[c/8] &= ~(1<<c%8);
}

void clear(){
    memset((void*) bitmap, 0, 128/8);
}

int lengthOfLongestSubstring(char * s){
    int ret = 0;
        
    for(int i = 0; i < strlen(s); i++){
        clear();
        int len = 0;
        for (int j=i; j < strlen(s); j++){
            if(exist(s[j])){
                break;
            }else{
                put(s[j]);
                //dump();
                len++;
            }
        }
        if(ret < len)
            ret = len;
    }
    
    clear();
    
    return ret;
}*/

char bitmap[128/8];//128bit = 16byte. bitmap for ascii

int exist(char c){
    return (bitmap[c/8]&(1<<c%8)) > 0;
}

void set(char c){ //set bit
    bitmap[c/8] |= (1<<c%8);
}

void clear(char c){ //clear bit
    bitmap[c/8] &= ~(1<<c%8);
}

void flush(){
    memset((void*) bitmap, 0, 128/8);
}

int lengthOfLongestSubstring(char * s){
    int ret=0;
    int i=0,j=0;
    
    flush();
    
    while(i<strlen(s) && j<strlen(s)){
        if(exist(s[j])){
            clear(s[i++]);
        }else{
            set(s[j++]);
            if(ret < j-i)
                ret = j-i;
        }
    }
    
    return ret;
}



