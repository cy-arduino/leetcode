/*

ori:
     [2],		<==step 3
    [3,4],		<==step 2
   [6,5,7],		<==step 1
  [4,1,8,3]

step 1:
     [2],		
    [3,4],		
   [7,6,10],	<==update
  [4,1,8,3]

step 2:
     [2],		
    [10,10],	<==update
   [7,6,10],		
  [4,1,8,3]

step 3:
	 [12],		<==update
    [10,10],		
   [7,6,10],		
  [4,1,8,3]

*/


int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    if(triangleSize ==0){
        return 0;
    }
    
    if(triangleSize > 1){ 
        for(int level = triangleSize-2; level >=0; level--){
            for(int i=0; i<triangleColSize[level]; i++){
                //int left = triangle[level+1][i];
                //int right = triangle[level+1][i+1];
                triangle[level][i] += (triangle[level+1][i]<triangle[level+1][i+1])?triangle[level+1][i]:triangle[level+1][i+1];
            }
        }
    }

    return triangle[0][0];
}

