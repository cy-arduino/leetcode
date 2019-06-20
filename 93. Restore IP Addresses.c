int maxRetSize = 1;


void getPart(char *ip, int partId, char ***pRet, int* pRetSize, int *intArr){
    
    for(int i=1; i<=3; i++){
        //printf("##getPart: ip=%s, partId=%d, i=%d\n", ip, partId, i);
        
        if(strlen(ip)-i <partId){
            //printf("remain ip too short, break\n");
            break;
        }
        if(strlen(ip)-i >partId*3){
            //printf("remain ip too long, continue!\n");
            continue;
        }
        
        char part[10]={0};
        strncpy(part,ip,i);
        
        int partInt = atoi(part);
        
        //printf("ip:%s, part:%s, partInt:%d\n", ip, part, partInt);
        
        if(partInt > 255){
            //printf("partInt too large, break\n");
            break;
        }
        if(ip[0] == '0' && i > 1){
            //printf("part can't start with 0 except 0\n");
            break;
        }
        
        //found one part!
        intArr[partId] = partInt;
        //printf("intArr = %d, %d, %d, %d\n", intArr[3], intArr[2], intArr[1], intArr[0]);
        
        getPart(&ip[i], partId-1, pRet, pRetSize, intArr);
        
        
        //found solution
        if(partId == 0){
            char *buf = malloc((3*4+3+1)*sizeof(char));
            //printf(">> %d.%d.%d.%d\n", intArr[3], intArr[2], intArr[1], intArr[0]);
            sprintf(buf, "%d.%d.%d.%d", intArr[3], intArr[2], intArr[1], intArr[0]);
            
            //realloc (*pRetSize) if need
            if((*pRetSize)+1 == maxRetSize){
                maxRetSize*=2;
                (*pRet) = realloc((*pRet), maxRetSize * sizeof(int*));
            }
            
            (*pRet)[(*pRetSize)++]=buf;
        }
    }
    
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** restoreIpAddresses(char * s, int* returnSize){
    char **ret = malloc(maxRetSize *sizeof(char*));
    *returnSize = 0;
    
    int intArr[4] = {-1,-1,-1,-1};
    
    
    getPart(s, 3, &ret, returnSize, intArr);
    
    return ret;
    
}

