#define MIN(a,b) ((a<=b)?a:b)


#if 0
//simple way
//O(n^2) algorithm
int maxArea(int* height, int heightSize){
    int max=0;
    int area=0;
    for(int i=0; i<heightSize-1; i++){
        for(int j=(i+1); j<heightSize; j++){
            area = (j-i)*MIN(height[i],height[j]);
            if(area > max)
                max = (j-i)*MIN(height[i],height[j]);
        }
    }
    return max;
}
#endif 

#if 0
//improve second loop
//O(n^2) algorithm
int maxArea(int* height, int heightSize){
    int max=0;
    int area=0;
    for(int i=0; i<heightSize-1; i++){  
        
        //improve 1
        if(height[i]==0)
            continue;
        
        //improve 2
        int next=i+1;
        if(max/height[i]>1)
            next=i+max/height[i];
        for(int j=next; j<heightSize; j++){

            area = (j-i)*MIN(height[i],height[j]);
            if(max < area)
                max = (j-i)*MIN(height[i],height[j]);
        }
    }
    return max;
}
#endif 

#if 1
//O(n) algorithm
int maxArea(int* height, int heightSize){
    int max=0;
    int area=0;
    
    int i=0; 
    int j=heightSize-1;
    
    while(i<j){
        //improve
        while(height[i]==0)
            i++;
        while(height[j]==0)
            j--;
        area = MIN(height[i], height[j]) * (j-i);
        if(max < area)
            max = area;
        
        //printf("i,j=%d,%d area=%d\n", i, j, area);
        
        if(height[i] < height[j]){
            i++;
        }else{
            j--;
        }
    }
    
    
    return max;
}
#endif