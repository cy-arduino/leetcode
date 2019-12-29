void swap(char *s, int i, int j){
    s[i] = s[i] ^ s[j];
    s[j] = s[j] ^ s[i];
    s[i] = s[i] ^ s[j];
}

char * revert_str(char *s, int len){
    if(len > 1){
        for(int i=0; i<len/2; i++){
            swap(s, i, len-1-i);
        }
    }
    return s;
}

char * reverseWords(char * s){
    //nothing to do
    if(s==NULL){
        printf("input is NULL\n");
        return s;
    }
    
    int s_len = strlen(s);
    printf("init: >>%s<<(%d)\n", s, strlen(s));

    //replace ' ' with '\0'
    for (int i = 0; i < s_len; i++){
        if(s[i] == ' '){
            s[i] = '\0';
        }  
    }

    //revert each word and put together
    char *to = s;
    for(int i=0; i< s_len;){
        char c = s[i];
        if(c!= '\0'){
            char *word = s + i;
            int word_len = strlen(word);
            printf("found word >>%s<<, len %d\n", word, word_len);
            revert_str(word, word_len);

            //append ' ' if not the first word
            if(to!=s){
                to[0] = ' ';
                to++;
            }

            //append next word
            if(word != to){
                memmove(to, word, word_len);
            }

            i += word_len;
            to += word_len;
        }else{
            i++;
        }
    }
    //append '\0'
    to[0] = '\0';
    //new len of s
    s_len = to - s;
    printf("revert each word and put together: >>%s<<(%d)\n", s, s_len);
    
    //revert all string
    revert_str(s, s_len);
    printf("revert all string: >>%s<<(%d)\n", s, s_len);

    return s;
}
