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

int isEqual(char *a, char *b, int len){
    for(int i=0; i<len; i++){
        if(a[i]!=b[i])
            return false;
    }
    return true;
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
        int i = 0;
        int next = i+1;
        
        for(i=0; i < lenHaystack-lenNeedle+1; i++){
            if(isEqual(haystack+i, needle, lenNeedle)){
                ret = i;
                break;
            }
        }
        
    }
    
    return ret;
}
