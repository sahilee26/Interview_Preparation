int Solution::longestValidParentheses(string A) {
    int len=A.length();
    int ans=0;
    stack<int> s;
    s.push(-1);
    for(int i=0; i<len; i++){
        if(A[i]=='('){
            s.push(i);
        }
        else{
            int ind=s.top();
            if(A[ind]=='('){
                s.pop();
                ans=max(ans, i-s.top());
            }
            else
                s.push(i);
        }
    }
    return ans;
}    
