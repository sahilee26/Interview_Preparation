int Solution::longestValidParentheses(string A) {
    int len=A.length();
    int ans=0;
    stack<int> s;
    s.push(-1);
    int valind=-1;
    for(int i=0; i<len; i++){
        if(A[i]=='('){
            s.push(i);
        }
        else{
            s.pop();
            if(!s.empty()){
                ans=max(ans, i-s.top());
            }
            else
                s.push(i);
        }
    }
    return ans;
}    
