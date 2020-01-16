bool check(char * s, int sLen, int sIdx, char ** wordDict, int wordDictSize, int *wordDictLen, bool *impossibleIdx){
    //printf("s: %s, curs:%s, sLen: %d, sIdx: %d\n", s, s+sIdx, sLen, sIdx);
    if(sIdx == sLen){
        //found;
        return true;
    }
    
    for(int i=0; i<wordDictSize; i++){
        //printf("#%d: %s\n", i, wordDict[i]);
        
        if((sLen-sIdx) >= wordDictLen[i] && !strncmp(s+sIdx, wordDict[i], wordDictLen[i])/*equal*/){
            //printf("match\n");
            //DP: calculated
            if(impossibleIdx[sIdx+wordDictLen[i]]){
                continue;
            }
            //printf("check recursively\n");
            bool ret = check(s, sLen, sIdx+wordDictLen[i], wordDict, wordDictSize, wordDictLen, impossibleIdx);
            if(ret){
                return true;
            }else{
                //DP: record impossible idx
                impossibleIdx[sIdx+wordDictLen[i]] = true;
            }
        }
    }
    return false;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    bool ret = false;
    
    //calculate length of each word in wordDict
    int *wordDictLen = malloc(wordDictSize * sizeof(int));
    if(!wordDictLen){
        //oom
        printf("OOM!\n");
        goto wordDictLen_error;
    }
    for(int i=0; i<wordDictSize; i++){
        wordDictLen[i] = strlen(wordDict[i]);
    }
    
    //DP: store result
    bool *impossibleIdx = calloc(strlen(s)+1, sizeof(bool));
    if(!impossibleIdx){
        printf("OOM!\n");
        goto impossibleIdx_error;
    }
    
    ret = check(s, strlen(s), 0, wordDict, wordDictSize, wordDictLen, impossibleIdx);

    if(impossibleIdx){
        free(impossibleIdx);
    }
impossibleIdx_error:
    //free wordDictLen
    if(wordDictLen){
        free(wordDictLen);
    }

wordDictLen_error:
    return ret;
}

