int getVersion(char **str){
    printf("getVersion: str=%s, ", *str);
    char *ori_str = *str;
    
    //i<=strlen(*str): loop to '\0'
    for(int i=0; i<=strlen(*str); i++){
        if((*str)[i]=='.'){
            (*str)[i] = '\0';
            (*str)+=i+1;
            break;
        }else if((*str)[i]=='\0'){
            (*str)+=i;
            break;
        }
    }
    printf("ori_str=%s(%p), new_str=%s(%p)\n", ori_str, ori_str, *str, *str);
    return atoi(ori_str);
}

int compareVersion(char * v1, char * v2){
    if(v1==NULL || v2==NULL){
        printf("invalid input!\n");
        return 0;
    }
    
    //get str end for check if reach the end
    char* v1_end = v1+strlen(v1);
    char* v2_end = v2+strlen(v2);
       
 
    printf("init: v1=%s, v2=%s\n", v1, v2);
    while(true){
        int v1_int = 0;
        int v2_int = 0;
        
        if(v1 < v1_end){
            v1_int = getVersion(&v1);
        }
        
        if(v2 < v2_end){
            v2_int = getVersion(&v2);
        }
        printf("compare: v1=%d, v2=%d\n", v1_int, v2_int);
        
        if(v1_int < v2_int){
            return -1;
        }else if(v1_int > v2_int){
            return 1;
        }else{
            //currently v1==v2
            
            //return 0 if both reach end
            if(v1>=v1_end && v2>=v2_end){
                //no more compare
                return 0;
            }
        }
    }
}

