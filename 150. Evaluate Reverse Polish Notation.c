
void push(int *stack, int *stackSize, int val, int maxStackSize){
    if((*stackSize)+1 <= maxStackSize){
        //printf("%s: %d\n", __func__, val);
        stack[(*stackSize)] = val;
        (*stackSize)++;
    }else{
        //TODO: handle error case!
        printf("%s: ERR, stackSize=%d, maxStackSize=%d\n", __func__, *stackSize, maxStackSize);
    }
}

int pop(int *stack, int *stackSize){
    if((*stackSize) > 0){
        (*stackSize)--;
        //printf("%s: %d\n", __func__, stack[(*stackSize)]);
        return stack[(*stackSize)];        
    }else{
        //TODO: handle error case!
        printf("%s: ERR, stackSize=%d\n", __func__, *stackSize);
        return 0;
    }
}

int evalRPN(char ** tokens, int tokensSize){
    int *stack = malloc(tokensSize * sizeof(int));
    int stackSize = 0;
    
    for(int i=0; i<tokensSize; i++){
        //printf("check tokens[%d]=%s, tokensSize=%d\n", i, tokens[i], tokensSize);
        
        //+,-,*,/
        if(tokens[i][0] == '+'){
            int a = pop(stack, &stackSize);
            int b = pop(stack, &stackSize);
            
            //printf("pop a=%d, b=%d, push %d\n",a, b, b+a);
            
            push(stack, &stackSize, b+a, tokensSize);
        }else if(tokens[i][0] == '-' && strlen(tokens[i]) == 1){
            int a = pop(stack, &stackSize);
            int b = pop(stack, &stackSize);
            
            //printf("pop a=%d, b=%d, push %d\n",a, b, b-a);
            
            push(stack, &stackSize, b-a, tokensSize);
        }else if(tokens[i][0] == '*'){
            int a = pop(stack, &stackSize);
            int b = pop(stack, &stackSize);
            
            //printf("pop a=%d, b=%d, push %d\n",a, b, b*a);
            
            push(stack, &stackSize, b*a, tokensSize);
        }else if(tokens[i][0] == '/'){
            int a = pop(stack, &stackSize);
            int b = pop(stack, &stackSize);
        
            //printf("pop a=%d, b=%d, push %d\n",a, b, b/a);
            
            push(stack, &stackSize, b/a, tokensSize);
        }else{
            //number
            int a = atoi(tokens[i]);
            
            //printf("push a=%d\n",a);
            
            push(stack, &stackSize, a, tokensSize);
        }
    }
    
    return pop(stack, &stackSize);

}

