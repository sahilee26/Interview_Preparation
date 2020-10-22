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
            // Pop the last opening bracket's index
            s.pop();
            
            if(!s.empty())
                ans=max(ans, i-s.top());
            else{
                // If stack is empty push the current index as 
                // base for new valid expression
                s.push(i);
            }
        }
    }
    return ans;
}    
