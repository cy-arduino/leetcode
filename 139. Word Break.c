int NOT_FOUND = 1;
    
bool match(char * s, int s_start, char ** wordDict, int wordDictSize, char* bitmap){    
    bool found = false;
    if(bitmap[s_start] != NOT_FOUND){
        char* cur_s = s + s_start;
        int s_len = strlen(cur_s);

        for(int i=0; i<wordDictSize; i++){
            char* word = wordDict[i];
            int word_len = strlen(word);

            if(s_len >= word_len && !strncmp(cur_s, word, word_len)){
                //printf("  word[%d]=%s, len=%d\n", i, wordDict[i], word_len);        
                if(s_len == word_len){
                    found = true;
                }else{
                    found = match(s, s_start+word_len, wordDict, wordDictSize, bitmap);
                }
                if(found)
                    break;
            }
        }
        
        if(!found){
            bitmap[s_start] = NOT_FOUND;
        }
    }
    return found;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
	//speedup, DP
	//TODO: use real bit
    char* bitmap = calloc(1000, sizeof(char));
    
    bool ret = match(s, 0, wordDict, wordDictSize, bitmap);
    
    free(bitmap);
        
    return ret;
}
