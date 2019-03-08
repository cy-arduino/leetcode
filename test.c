int getlen(char* s){
    if(s == NULL)
        return 0;
    
    int i=0;

    while(s[i]!='\0'){
        //printf("s[%d]=%c ", i, s[i]);
        i++;
    }
    return i;
}

int strStr(char* haystack, char* needle) {
    int ret=-1;
    //printf("haystack=%s\n", haystack);
    //printf("needle=%s\n", needle);
    
    if(needle[0]=='\0'){
        //printf("empty needle\n");
        ret = 0;
    }else{
        int lenHaystack = getlen(haystack);
        int lenNeedle = getlen(needle);
        
        //printf("lenHaystack = %d, lenNeedle = %d\n", lenHaystack, lenNeedle);
        int i = 0
        int next = i+1;
        
        while(i < lenHaystack){
            
        }
        
    }
    
    return ret;
}
