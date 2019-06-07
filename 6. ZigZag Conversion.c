/*

input: ABCDEFGHI, 3
================
row0: A   E   I
row1: B D F H
row2: C   G
================
output: AEIBDFHCG



diff of each row:
	first jump: 2*(numRows-row)-2
	second jump: 2*(numRows-(numRows-1-row))-2

	special case: latest row=row0

*/
int getdiff1(int numRows, int row){
	if (row + 1 == numRows)
		row =0;
	
	return 2*(numRows-row)-2;
}

int getdiff2(int numRows, int row){
	return getdiff1(numRows, numRows-1-row);
}


char* convert(char *s, int numRows){
    if(numRows==1)
        return s;
    
    //printf("input s=%s, numRows=%d, len(s)=%d\n", s, numRows, strlen(s));
	
	char *ret = (char*) malloc(strlen(s)*sizeof(char)+1);
    
	int retIdx=0;
	
	for(int r=0; r<numRows; r++){
		int i=r;
		
		while(i < strlen(s)){
            
			if(i < strlen(s))
				ret[retIdx++] = s[i];
			else
				break;
			i+=getdiff1(numRows,r);
            
			if(i < strlen(s))
				ret[retIdx++] = s[i];
			else
				break;
			i+=getdiff2(numRows,r);	
					
		}
        
        ret[strlen(s)]='\0';
	}
    
    
	return ret;
}