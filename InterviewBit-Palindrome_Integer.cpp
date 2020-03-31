int Solution::isPalindrome(int A) {
    if(A<0)
        return false;
    int x=A;
    int len=0;
    while(x){
        x/=10;
        len++;
    }
    int y=len-1;
    while(A){
        int c=A/(pow(10,y));
        int d=A%10;
        if(c!=d){
            return false;
        }
        A-=(c*pow(10,y));
        A/=10;
        y-=2;
    }
    return true;
}
