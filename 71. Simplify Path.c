char * simplifyPath(char * path){

    char** buf = malloc( strlen(path) * sizeof(char*));
    int bufSize=0;
    
    char* tok = strtok(path, "/");
    
    while(tok != NULL){
               
        //printf("tok=%s\n", tok);
        
        if(0==strcmp(tok, ".")){
            //ignore thi tok
        }else if( 0== strcmp(tok, "..")){
            //ignore this tok and buf back 1
            if(bufSize>0)
                bufSize--;
        }else{
            //take this tok
            buf[bufSize++] = tok;
        }
        
        tok = strtok(NULL, "/");
    }
    
    /*printf("dump buf: ");
    for(int i=0; i<bufSize; i++){
        printf("%s ", buf[i]);
    }
    printf("\n");*/
    
	
	//use buf to rebuild path
    int pathIdx=0;
    for(int i=0; i<bufSize; i++){
        path[pathIdx++] = '/';
        for(int j=0; j<strlen(buf[i]); j++){
            path[pathIdx++] = buf[i][j];
        }
    }
    path[pathIdx++] = '\0';
    
	//handle special case
    if(strlen(path) == 0){
        path[0] = '/';
        path[1] = '\0';
    }
    
    
    free(buf);
    
    return path;
}

