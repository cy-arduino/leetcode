typedef struct bitmap_t{
    int size;
    unsigned char *data;
}bitmap;

bitmap * build_bit_map(int size){
    bitmap* map = calloc(1, sizeof(bitmap));
    
    map->size = size;
    
    int data_size = size/8;
    if(size%8){
        data_size++;
    }
    
    map->data = (unsigned char*)calloc(data_size, sizeof(unsigned char));
    
    return map;
}

int bit_is_set(bitmap *map, int bit){    
    int data_idx = bit/8;
    int bit_idx = bit%8;
    
    unsigned char mask = 1 << bit_idx;
    if(mask & map->data[data_idx]){
        printf("bit_is_set: %d\n", bit);
        return 1;
    }
    
    return 0;
}

void bit_set(bitmap *map, int bit){
    int data_idx = bit/8;
    int bit_idx = bit%8;
    
    unsigned char mask = 1 << bit_idx;
    map->data[data_idx] |= mask;

    return;
}

int findDuplicate(int* nums, int numsSize){
    bitmap *map = build_bit_map(numsSize);
    
    for(int i=0; i<numsSize; i++){
        if(bit_is_set(map, nums[i])){
            return nums[i];
        }else{
            bit_set(map, nums[i]);
        }
    }
    return -1;
}

