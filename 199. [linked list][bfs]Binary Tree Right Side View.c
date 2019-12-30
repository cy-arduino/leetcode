////////////////
//list
////////////////
typedef struct Node{    
    struct Node* next;
    struct Node* prev;
    void* data;
}listNode;

typedef struct List{
    listNode *head;
    listNode *tail;
    int size;
}list;

listNode * buildNode();
list * buildList();
void clearList(list *l);
void destroyList(list *l);
void pushHead(list *l, void* data);
void pushTail(list *l, void* data);
void * popHead(list *l);
void * popTail(list *l);

listNode * buildNode(){
    return (listNode *) calloc(1, sizeof(listNode));
}

list * buildList(){
    list *l = (list *)malloc(1*sizeof(list));
    l->head = l->tail = NULL;
    l->size = 0;
    return l;
}

void clearList(list *l){
    if(l){
        while(l->size){
            popHead(l);
        }
    }
}

void destroyList(list *l){
    if(l){
        clearList(l);
        free(l);
    }
}

void pushHead(list *l, void* data){
    if(!l){
        printf("error: no list\n");
        return;
    }

    listNode *node = buildNode();
    if(!node){
        printf("error: nomem\n");
        return;
    }
    node->data = data;
    node->prev = NULL;

    if(l->size){
        node->next = l->head;
        l->head->prev = node;
    }else{
        l->tail = node;
    }
    l->head = node;
    l->size++;
}

void pushTail(list *l, void* data){
    if(!l){
        printf("error: no list\n");
        return;
    }

    listNode *node = buildNode();
    if(!node){
        printf("error: nomem\n");
        return;
    }
    node->data = data;
    node->next = NULL;

    if(l->size){
        node->prev = l->tail;
        l->tail->next = node;
    }else{
        l->head = node;
    }
    l->tail = node;
    l->size++;
}

void * popHead(list *l){
    if(!l){
        printf("error: no list\n");
        return NULL;
    }
    if(!l->size){
        printf("error: list empty\n");
        return NULL;
    }

    void *ret = NULL;

    listNode *node = l->head;
    l->head = node->next;
    l->size--; 

    if(l->size){
        l->head->prev = NULL;
    }else{
        l->head = l->tail = NULL;
    }
    ret = node->data;
    free(node);

    return ret;
}

void * popTail(list *l){
    if(!l){
        printf("error: no list\n");
        return NULL;
    }
    if(!l->size){
        printf("error: list empty\n");
        return NULL;
    }

    void *ret = NULL;

    listNode *node = l->tail;
    if(node->prev){
        l->tail = node->prev;
        l->tail->next = NULL;
    }
    l->size--;
    ret = node->data;
    free(node);

    if(!l->size){
        l->head = l->tail = NULL;
    }

    return ret;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize){
    int *ret = NULL;

    *returnSize = 0;
    
    if(!root)
        return ret;

    list *retList = buildList();
    if(!retList){
        printf("error: out of memory!\n");
        return ret;
    }
    list *thisLevel = buildList();
    if(!retList){
        printf("error: out of memory!\n");
        return ret;
    }

    list *nextLevel = buildList();
    if(!nextLevel){
        printf("error: out of memory!\n");
        return ret;
    }

    pushTail(thisLevel, root);

    while(thisLevel->size){
        if(!thisLevel->size){
            //done
            break;
        }

        //get right side view of this level
        pushTail(retList, thisLevel->tail->data);

        //build next level
        while(thisLevel->size){
            struct TreeNode *node = popHead(thisLevel);
            if(node->left){
                pushTail(nextLevel, node->left);
            }
            if(node->right){
                pushTail(nextLevel, node->right);
            }
        }

        //swap thisLevel && nextLevel
        list *tmp = thisLevel;
        thisLevel = nextLevel;
        nextLevel = tmp;

        //clear next level
        clearList(nextLevel);
    }

    //printf("ret list size=%d\n", retList->size);
    if(retList->size){
        ret = malloc(retList->size * sizeof(int));
        while(retList->size){
            int *data = popHead(retList);
            if(data){
                //printf("data #%d: %d\n", *returnSize, *data);
                ret[(*returnSize)++] = *data;
            }            
        }
    }

    return ret;
}
