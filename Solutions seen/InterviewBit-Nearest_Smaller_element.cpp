vector<int> Solution::prevSmaller(vector<int> &A) {
    int len=A.size();
    vector<int> ans(len, -1);
    
    stack<int> s;
    
    for(int i=0; i<A.size(); i++){
        while(!s.empty() && s.top()>=A[i]){
            s.pop();
        }
        if(!s.empty() && s.top()<A[i]){
            ans[i]=s.top();
        }
        else{
            ans[i]=-1;
        }
        s.push(A[i]);
    }
    return ans;
}
