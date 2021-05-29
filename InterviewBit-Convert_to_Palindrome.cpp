bool isPalindrome(string s, int i, int j, int count1){

    // base case
    if(i==j)
        return 1;
        
    // base case
    if(j==i+1){
        
        if(s[i]==s[j] || count1==0)
            return 1;
        else 
            return 0;
    }
    // if match 
    if(s[i]==s[j]){
        
        return isPalindrome(s, i+1, j-1, count1);
    }
    
    else{
       
        count1++;
        if(count1>=2)
            return 0;
        else
            return isPalindrome(s, i+1, j, count1) || isPalindrome(s, i, j-1, count1);
    }
        
}
int Solution::solve(string A) {
    int len=A.size();
    int count1=0;

    
    if(A[0]==A[len-1] && isPalindrome(A, 1, len-2, count1))
        return 1;
    else{
        count1++;
        if(isPalindrome(A, 1, len-1, count1) || isPalindrome(A, 0, len-2, count1))
            return 1;
        else
            return 0;
    }
}
