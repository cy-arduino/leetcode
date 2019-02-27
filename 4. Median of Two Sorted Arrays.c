//assume lenA <= lenB to makesure j>=0
//assume all numbers >= 0!
//assume lenA>0, lenB>0
double findMid(int * A, int lenA, int * B, int lenB, int iMin, int iMax){
    int i = (iMin + iMax)/2+(iMin + iMax)%2;
    int j = (lenA + lenB)/2-i;
    
    int leftA = (i==0)?B[j-1]:A[i-1];
    int leftB = (j==0)?A[i-1]:B[j-1];
    int leftMax = (leftA>=leftB)?leftA:leftB;
    int rightA = (i==lenA)?B[j]:A[i];
    int rightB = (j==lenB)?A[i]:B[j];
    int rightMin = (rightA<=rightB)?rightA:rightB;
    
    int iMinNew = iMin;
    int iMaxNew = iMax;
   
    if(rightA>=leftA && rightB>=leftB && rightA>=leftB && rightB>=leftA){
        //found
		
        if((lenA+lenB)%2)
            return (double)rightMin;
        else
            return ((double)rightMin + leftMax)/2;
    }else{
        //not found
		
        if(leftA>rightB){
            iMinNew = iMin;
            iMaxNew = i;
        }else{
            iMinNew = i;
            iMaxNew = iMax;
        }
        
        //handle special case
        if((iMax-iMin)==1 && (iMaxNew-iMinNew)==1){
            iMaxNew--;
        }
        
        return findMid(A, lenA, B, lenB, iMinNew, iMaxNew);
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if(nums1Size >= nums2Size)
        return findMid(nums2, nums2Size, nums1, nums1Size, 0, nums2Size);
    else
        return findMid(nums1, nums1Size, nums2, nums2Size, 0, nums1Size);
}