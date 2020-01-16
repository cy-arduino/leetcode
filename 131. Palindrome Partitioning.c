typedef struct LL{
    struct LL *next;
    char *palindrome;
    int palindromeLen;
}ll;

typedef struct Result{
    char ***ret;
    int retSize;
    int maxRetSize;
    int *retColSizes;
}result;

void dumpResult(result *r){
    return; //debug
    printf("\n===================\n");
    printf("retSize=%d, maxRetSize=%d\n", r->retSize, r->maxRetSize);
    for(int i=0; i<r->retSize; i++){
        printf("#%d: ", i);
        for(int j=0; j<r->retColSizes[i]; j++){
            printf("%s\t", r->ret[i][j]);
        }
        printf("\n");
    }
}

#define RESULT_INCREASE_SIZE 10
result * buildResult(){
    result *ret = calloc(1, sizeof(result));
    ret->retSize = 0;
    ret->maxRetSize = 100;
    ret->retColSizes = calloc(ret->maxRetSize, sizeof(int));
    ret->ret = calloc(ret->maxRetSize, sizeof(char **));
    
    return ret;
}

void appendResult(result *r, char **row, int colSize){
    /*
    //debug
    printf("append: ");
    for(int i=0; i<colSize; i++){
        printf("%s\t", row[i]);
    }
    printf("\n");
    */
    
    if(r->retSize+1 >= r->maxRetSize){
        char ***newRet = realloc(r->ret, (r->maxRetSize+RESULT_INCREASE_SIZE)*sizeof(char **));
        if(!newRet){
            printf("oom\n");
            return;
        }
        int *newRetColSizes = realloc(r->retColSizes, (r->maxRetSize+RESULT_INCREASE_SIZE)*sizeof(int));
        if(!newRetColSizes){
            printf("oom\n");
            return;
        }
        
        r->ret = newRet;
        r->retColSizes = newRetColSizes;
        r->maxRetSize += RESULT_INCREASE_SIZE;
    }
    
    r->retColSizes[r->retSize] = colSize;
    r->ret[r->retSize] = calloc(colSize, sizeof(char*));
    for(int i=0; i<colSize; i++){
        r->ret[r->retSize][i]=calloc(strlen(row[i])+1, sizeof(char));
        strncpy(r->ret[r->retSize][i], row[i], strlen(row[i]));
    }
    r->retSize++;
}

void destroyResult(result *r){
    //preserv ret && retColSizes
    if(!r){
        printf("invalid input %p!!\n", r);
    }
    free(r);
}

bool isPalindromes(char *s, int len){
    if(!len){
        printf("invalid len\n");
        return false;
    }
    if(len == 1){
        return true;
    }
    
    for(int i=0; i<len/2; i++){
        if(s[i]!=s[len-1-i]){
            return false;
        }
    }
    return true;
}

void calculatePalindrome(char * s, ll **palindromes, int start){
    for(int i=start; i<strlen(s); i++){
        if(isPalindromes(s+start, i-start+1)){
            //insert one node
            ll *node = calloc(1, sizeof(ll));
            node->palindrome = s+start;
            node->palindromeLen = i-start+1;
            node->next = palindromes[start];
            palindromes[start] = node;
            
            if(i+1 <strlen(s) && !palindromes[i+1]){
                calculatePalindrome(s, palindromes, i+1);
            }
        }
    }
}

void findCombination(int sLen, ll **palindromes, int palindromeIdx, char **buffer, int bufIdx, result *r){
    ll * node = palindromes[palindromeIdx];
    while(node){
        strncpy(buffer[bufIdx], node->palindrome, node->palindromeLen);
        buffer[bufIdx][node->palindromeLen] = '\0';
        
        if(palindromeIdx+node->palindromeLen == sLen){
            //found
            appendResult(r, buffer, bufIdx+1);
            dumpResult(r);
        }else{
            findCombination(sLen, palindromes, palindromeIdx+node->palindromeLen, buffer, bufIdx+1, r);
        }
        node = node->next;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** partition(char * s, int* returnSize, int** returnColumnSizes){
    if(!strlen(s)){
        printf("invalid input\n");
        return NULL;
    }
    
    *returnSize = 0;
    
    ll **palindromes = calloc(strlen(s), sizeof(ll *));
    calculatePalindrome(s, palindromes, 0);
    
    /* 
    //debug
    for(int i=0; i<strlen(s); i++){
        printf("#%d: ", i);
        ll *p = palindromes[i];
        while(p){
            char *s = calloc((p->palindromeLen+1), sizeof(char));
            strncpy(s, p->palindrome, p->palindromeLen);
            printf("%s\t", s);
            p = p->next;
        } 
        printf("\n");
    }*/
    
    result *r = buildResult();
    
    //dfs to find all combination
    char **buffer = calloc(strlen(s), sizeof(char*));
    for(int i=0; i<strlen(s); i++){
        buffer[i] = calloc(strlen(s)+1, sizeof(char));
    }
    findCombination(strlen(s), palindromes, 0, buffer, 0, r);
    
    
    //destroy buffer
    //for(int i=0; i<strlen(s); i++){
    //    free(buffer[i]);
    //}
    //free(buffer);
    
    *returnSize = r->retSize;
    *returnColumnSizes = r->retColSizes;
    //destroyResult(r);
    return r->ret;
}

