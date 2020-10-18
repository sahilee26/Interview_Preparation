vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    
    // we maintain a deque that stores that indexes that are 
    // useful in current window of size k and useful are those which are grater than all
    //elements to right of it in current window  
    // front of dequeue will always be greatest element in the dequeue
    vector<int> res;
    
    if(A.empty())
        return res;
    
    deque<int> dq;
    dq.push_back(0);
    int len=A.size();  
    int i=1;
    for(; i<min(B, len); i++){
        while(!dq.empty() && A[dq.back()]<A[i])
            dq.pop_back();
        dq.push_back(i);
    }
    
    int ans=A[dq.front()];
    res.push_back(ans);
    
    for(; i<A.size(); i++){
        
        if(!dq.empty() && (dq.front()<=i-B))
            dq.pop_front();
            
        while(!dq.empty() && A[dq.back()]<A[i])
            dq.pop_back();
        dq.push_back(i);
        
        ans=A[dq.front()];
        res.push_back(ans);
    }
    return res;
}
