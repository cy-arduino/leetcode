char bitmap[128/8];//bitmap for ascii, 128bit = 16byte. 

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

//i: substring's left idx
//j: substring's right idx
//ret: maxium of j-i
//time complexity: O(n)
//space: O(1) <== 128 bit for ascii
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
