int Solution::largestRectangleArea(vector<int> &A) {
    
    stack<int> s;
    
    int ans=0;
    int i=0;
    
    while(i<A.size()){
        if(s.empty() || A[s.top()]<=A[i])
            s.push(i++);
        else{
            int tp=s.top();
            s.pop();
            int new_area =A[tp]*(s.empty()? i : i-s.top()-1);
            ans=max(ans, new_area);
        }
    }
    while(!s.empty()){
        int tp=s.top();
        s.pop();
        int new_area =A[tp]*(s.empty()? i : i-s.top()-1);
        
        ans=max(ans, new_area);
    }
    return ans;
}
