//use BFS!

//bitmap
//////////////////
struct BitMap{
	int maxBit;
	int bufSize;
	unsigned char *buf;
};


const char *bit_rep[16] = {
    [ 0] = "0000", [ 1] = "0001", [ 2] = "0010", [ 3] = "0011",
    [ 4] = "0100", [ 5] = "0101", [ 6] = "0110", [ 7] = "0111",
    [ 8] = "1000", [ 9] = "1001", [10] = "1010", [11] = "1011",
    [12] = "1100", [13] = "1101", [14] = "1110", [15] = "1111",
};
void bitMapDump(struct BitMap in){

#if 0
	for(int i=in.bufSize-1; i>=0; i--){
		printf("%s%s(%u) ", bit_rep[in.buf[i]>>4], bit_rep[in.buf[i]&0x0f], in.buf[i]);
	}
	printf("\n");
#endif
}

struct BitMap bitMapGen(int maxBit){
	struct BitMap ret;
	ret.maxBit = maxBit;
	
	ret.bufSize = maxBit/8;
	if(maxBit%8){
		ret.bufSize++;
	}
	ret.buf = calloc(ret.bufSize, sizeof(unsigned char));
	
	return ret;
}

void bitMapDestroy(struct BitMap in){
	free(in.buf);
}

//clear all bits
void bitMapFlush(struct BitMap in){
	for(int i=0; i<in.bufSize;i++){
		in.buf[i] = 0;
	}
}

//set 1 bit
void bitMapSet(struct BitMap in, int bit, int val){
	int setByte = bit/8;
	int setBit = bit%8;
	
	//printf("%s: bit=%d, setByte=%d, setBit=%d, val=%d\n", __func__, bit, setByte, setBit, val);
	
	if(val){
		//set bit
		in.buf[setByte] |= 1<<setBit;
	}else{
		//clear bit
		in.buf[setByte] &= ~(1<<setBit);
	}
}

int bitMapIsSet(struct BitMap in, int bit){
	int setByte = bit/8;
	int setBit = bit%8;
	
	return (in.buf[setByte] & 1<<setBit)!=0;
}

void bitMapCopy(struct BitMap dst, struct BitMap src){
    for(int i=0; i<dst.bufSize; i++){
        dst.buf[i] = src.buf[i];
    }
}
//////////////////

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

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
        
    bool endWordExist = 0;
    int endWordIdx = -1;
    for(int i=0; i<wordListSize; i++){
        if(0== strcmp(wordList[i], endWord)){
            //endWord exist
            endWordExist = 1;
            endWordIdx = i;
        }
    }
    if(!endWordExist){
        printf("endWord not exist!");
        return 0;
    }
    
    
    struct BitMap *graph = malloc(wordListSize * sizeof(struct BitMap));
    for(int i=0; i<wordListSize; i++){
        graph[i] = bitMapGen(wordListSize);
    }
    
    //build graph
    for(int i=0; i<wordListSize; i++){
        for(int j=0; j<wordListSize; j++){
            if(isTrans(wordList[i], wordList[j])){
				bitMapSet(graph[i], j, 1); 
			}
        }
    }
    
    struct BitMap queue = bitMapGen(wordListSize);
	struct BitMap newQueue = bitMapGen(wordListSize);
	struct BitMap mask = bitMapGen(wordListSize);
	
    int queueSize = 0;
    int newQueueSize = 0;
    int found = 0;

    int transCnt =1; //head count 1
    
    //build the first queue
    for(int i=0; i<wordListSize; i++){
        if(isTrans(beginWord, wordList[i])){
            if(0==strcmp(wordList[i],endWord)){
                //found
                transCnt++;
                found = 1;
                goto OUT;
            }

			if(! bitMapIsSet(queue, i)){
				bitMapSet(queue, i, 1);
				queueSize++;
			}
        }
    }
    
    //loop until we found the solution
    found = 0;
    while(queueSize){
        transCnt++;        
        
        newQueueSize = 0;
		
        for(int i=0; i<wordListSize; i++){
			if(bitMapIsSet(queue, i)){
				int thisRoot=i;
				
				if(0==strcmp(wordList[thisRoot],endWord)){
					//found solution!
					found = 1;
					goto OUT;
					break;
				}
				
				if(!bitMapIsSet(mask, thisRoot)){			
                    bitMapSet(mask, thisRoot, 1);
                    
					for(int j=0; j<wordListSize; j++){
						if(bitMapIsSet(graph[thisRoot],j) && !bitMapIsSet(newQueue,j)){
                            bitMapSet(newQueue, j, 1);
                            newQueueSize++;                            
                        }
				    }					
				}
				
			}
			
        }
        
        bitMapCopy(queue, newQueue);
        queueSize = newQueueSize;
    }
 
 OUT:
    bitMapDestroy(queue);
    bitMapDestroy(newQueue);
    bitMapDestroy(mask);
	
	for(int i=0; i<wordListSize; i++){
		bitMapDestroy(graph[i]);
	}

    if(found)
        return transCnt;
    else
        return 0;
}

