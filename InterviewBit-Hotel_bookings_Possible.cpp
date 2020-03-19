bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int len=arrive.size();
    vector<pair<int,int> > A;
    for(int i=0; i<len; i++){
        A.push_back(make_pair(arrive[i], 1));
        A.push_back(make_pair(depart[i], 0));
    }
    sort(A.begin(), A.end());
    int curr_active=0;
    for(int i=0; i<2*len; i++){
        if(A[i].second==1){
            curr_active++;
        }
        else if(A[i].second==0){
            curr_active--;
        }
        if(curr_active>K)
            return false;
    }
    return true;
    
}
