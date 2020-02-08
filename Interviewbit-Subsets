#define ll long long

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    int n=A.size();
    vector<vector <int> >v;
    for(int i=0; i<(1<<n); i++){
        vector<int> c;
        for(int j=0; j<n; j++){
            if(i&(1<<j))
                c.push_back(A[j]);
        }
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    return v;
}
