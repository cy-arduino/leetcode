bool isPalindrome(int x) {
    int a=x;
    int reverse=0;
    
    if(x<0)
        return false;
    else{
        while(a){
            reverse=reverse*10+a%10;
            a=a/10;
        }
        
        return x==reverse;
    }
    
}
