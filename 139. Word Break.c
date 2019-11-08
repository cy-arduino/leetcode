//DFS
bool match(char * s, int s_start, char ** wordDict, int wordDictSize, char* bitmap){    
    //printf("s=%s, len=%d\n", s+s_start, strlen(s+s_start));   
    bool found = false;
    if(!(bitmap[s_start/8] & (0x1 << s_start%8))){
        char* cur_s = s + s_start;
        int cur_s_len = strlen(cur_s);

        for(int i=0; i<wordDictSize; i++){
            char* word = wordDict[i];
            int word_len = strlen(word);

            if(cur_s_len >= word_len && !strncmp(cur_s, word, word_len)){
                //printf("  word[%d]=%s, len=%d\n", i, wordDict[i], word_len);        
                if(cur_s_len == word_len){
                    found = true;
                }else{
                    found = match(s, s_start+word_len, wordDict, wordDictSize, bitmap);
                }
                if(found)
                    break;
            }
        }

        //DP, 1 means start from s_start is not found
        if(!found){
            bitmap[s_start/8] |= (0x1 << (s_start%8));
        }
    }
    return found;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    char* bitmap = calloc(strlen(s)/8 + 1, sizeof(char));
    
    bool ret = match(s, 0, wordDict, wordDictSize, bitmap);
    
    free(bitmap);
        
    return ret;
}
