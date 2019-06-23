
void dump(char ** wordList, int *wordListSize){
    //printf("%s: ", __func__);
    for(int i=0; i<(*wordListSize); i++){
        printf("%s, ", wordList[i]);
    }
    printf("\n");
}

int pop(char ** wordList, int *wordListSize, int i, int *trans){
    
    //printf("pop %d before: ", i);
    //dump(wordList, wordListSize);
    
    //error handle
    if(i>= (*wordListSize) || i<0){
        printf("%s: ERROR: invalid i=%d\n", __func__, i);
        return -1;
    }
    
    if(i == (*wordListSize)-1){
        //special case
        (*wordListSize)--;
    }else{    
        //move list[i] to list end and decrease list size
        //printf("%s: wordList[%d]=%s, wordListSize =%d\n",__func__, i, wordList[i], *wordListSize);
        char *tmp = wordList[i];
        memmove(&(wordList[i]), &(wordList[i+1]), ((*wordListSize)-1-i) * sizeof(char *));
        
        int tmp2 = trans[i];
        memmove(&trans[i], &trans[i+1], ((*wordListSize)-1-i) * sizeof(int));
        
        (*wordListSize)--;
        
        wordList[(*wordListSize)] = tmp;   
        trans[(*wordListSize)] = tmp2;
        
    }
    
    //printf("pop after: ");
    //dump(wordList, wordListSize);
    
    return 0;
}

int push (char ** wordList, int *wordListSize, int i, int maxWordListSize, int *trans){
    //printf("push %d before: ", i);
    //dump(wordList, wordListSize);
    
    //error handle
    if((*wordListSize) >= maxWordListSize){
        printf("%s: ERROR: wordListSize=%d, maxWordListSize=%d\n", wordListSize, maxWordListSize);
        return -1;
    }
    
    //increase list size and insert the end of list into list[i] and 
    (*wordListSize)++;
    
    char *tmp = wordList[(*wordListSize)-1];
    memmove(&(wordList[i+1]), &(wordList[i]), ((*wordListSize)-1-i) * sizeof(char *));
    wordList[i] = tmp;    
    
    int tmp2 = trans[(*wordListSize)-1];
    memmove(&(trans[i+1]), &(trans[i]), ((*wordListSize)-1-i) * sizeof(int));
    trans[i] = tmp2;
    
    //printf("push after: ");
    //dump(wordList, wordListSize);
    
    return 0;
}

bool isTrans(char *a, char *b){
    if(strlen(a) != strlen(b)){
        printf("%d: ERROR, strlen(%s)=%d, strlen(s)=%d\n", __func__, a, strlen(a), b, strlen(b));
        return false;
    }
    
    int diff = 0;
    for(int i=0; i<strlen(a); i++){
        if(a[i] != b[i]){
            diff++;
            
            if(diff > 1)
                return false;
        }
    }
    
    return diff==1;
}


//return: 1:solution found and update
int dfs(char ** wordList, int *wordListSize, int maxWordListSize, char *beginWord, char *endWord, int curTransCnt, int *minTransCnt, int *trans){

#if 0
    printf("%s: wordListSize=%d, maxWordListSize=%d, beginWord=%s, endWord=%s, curTransCnt=%d, minTransCnt=%d\n", 
           __func__, *wordListSize, maxWordListSize, beginWord, endWord, curTransCnt, *minTransCnt);
    dump(wordList, wordListSize);
#endif
    
    
    
    if((*minTransCnt)>0 && curTransCnt+1 >= (*minTransCnt)){
        //not the shortest solution, break this path;
        //printf("Too long, break\n");
        return 0;
    }
    
    for(int i=0; i<(*wordListSize); i++){
        
        //found 1 trans
        if(isTrans(beginWord, wordList[i])){
            curTransCnt++;
            
            //found solution
            if(0==strcmp(wordList[i], endWord)){
                printf(">>found a solution: %d\n", curTransCnt);
                
                if((*minTransCnt) == 0 || ((*minTransCnt) > 0 &&curTransCnt < (*minTransCnt))){
                    (*minTransCnt) = curTransCnt;    
                    printf(">>>update solution\n");
                }
                return 1;
            }
            
            //printf("trans[%d]=%d, curTransCnt=%d\n", i, trans[i], curTransCnt);
            if(trans[i] && trans[i]<curTransCnt){
                //not the shortest solution, break this path;
                printf("BREAK\n");
                return 0;
            }
            
            int ret =0;
            
            pop(wordList, wordListSize, i, trans);
            //DFS search
            ret = dfs(wordList, wordListSize, maxWordListSize, wordList[(*wordListSize)], endWord, curTransCnt, minTransCnt, trans);
            push(wordList, wordListSize, i, maxWordListSize, trans);
            
            if(ret){
                //printf("trans[%d] = %d, curTransCnt=%d\n", i, trans[i], curTransCnt);
                //can found solutoin
                if(!trans[i] || (trans[i] &&curTransCnt < trans[i])){
                    trans[i] = curTransCnt;
                }
            }
            
            curTransCnt--;
        }
    }
    return 0;
    
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    
    bool endWordExist = 0;
    for(int i=0; i<wordListSize; i++){
        if(0== strcmp(wordList[i], endWord)){
            //endWord exist
            endWordExist = 1;
        }
    }
    if(!endWordExist){
        printf("endWord not exist!");
        return 0;
    }
    
    //use DP to speedup!
    int minToHere;
    
    int *trans = calloc(wordListSize, sizeof(int));
    
    int minTransCnt = 0;
    int curWordListSize = wordListSize;
    dfs(wordList, &curWordListSize, wordListSize, beginWord, endWord, 1/*beginWord is the 1st*/, &minTransCnt, trans);

    return minTransCnt;
}

