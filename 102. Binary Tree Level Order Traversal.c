/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct MyListNode {
    struct TreeNode *node;
    struct MyListNode *next;
};



void queueInsHead(struct MyListNode ** q, struct TreeNode *n){
    struct MyListNode *ln= malloc(sizeof(struct MyListNode));
    ln->node = n;
    ln->next = *q;
    *q = ln;
}

struct TreeNode * queueRmHead(struct MyListNode ** q){
    struct MyListNode *ln = *q;
    *q = (*q)->next;
    
    struct TreeNode *ret = ln->node;
    free(ln);
    
    return ret;
}

void dumpQueue(char *s, struct MyListNode **q){
    struct MyListNode *iter = (*q);
    
    printf("%s: ", s);
    while(iter){
        printf("%d ", iter->node->val);
        
        iter=iter->next;
    }
    printf("\n");
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int **ret;
    int retSize=0;
    int maxRetSize=100;
    
    ret = malloc(maxRetSize * sizeof(int*));
    *returnColumnSizes = malloc(maxRetSize * sizeof(int));
    
    struct MyListNode *queue = NULL;
    struct MyListNode *tmpQueue = NULL;
    
    if(!root){
        *returnSize = 0;
        return ret;        
    }
    
    //put the root into queue
    queueInsHead(&queue, root);
    //dumpQueue("Only root queue", &queue);

    //START
    while(queue){
        
        //put all next level node into tmpQueue
        struct MyListNode *queueIter = queue;
        int queueSize = 0;
        while(queueIter){
            queueSize++;
            if(queueIter->node->left){
                queueInsHead(&tmpQueue, queueIter->node->left);
            }
            if(queueIter->node->right){
                queueInsHead(&tmpQueue, queueIter->node->right);
            }
            queueIter = queueIter->next;
        }
        
        //dumpQueue("tmpQueue", &tmpQueue);
        
        //put all items in queue to ret and returnColumnSizes
        if(retSize +1 == maxRetSize){
            //realloc
            maxRetSize *=2;
            int **newRet = realloc(ret, maxRetSize * sizeof(int*));
            int *newRetColSize = realloc(*returnColumnSizes, maxRetSize * sizeof(int));
            
            printf("realloc ret, size=%d\n", maxRetSize);
            if(newRet && newRetColSize){
                ret = newRet;
                *returnColumnSizes = newRetColSize;
            }else{
                printf("ERROR\n");
            }
        }
        ret[retSize] = malloc(queueSize * sizeof(int));
        
        (*returnColumnSizes)[retSize] = queueSize;
        
        int colIdx = 0;
		while(queue){
			struct TreeNode *tn = queueRmHead(&queue);
			ret[retSize][colIdx++] = tn->val;
		}
        retSize++;
        
        //printf("queueSize = %d, retSize=%d\n", queueSize);

        //move all items from tmpQueue to queue;
        while(tmpQueue){
            struct TreeNode *tn = queueRmHead(&tmpQueue);
            queueInsHead(&queue, tn);
        }
    
    }
    
    
    *returnSize = retSize;
    return ret;
}

