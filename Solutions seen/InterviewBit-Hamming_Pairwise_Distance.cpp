#define MOD 1000000007
#define ll long long
int Solution::hammingDistance(const vector<int> &A) {
    
    ll len=A.size();
    ll ans=0;
    ll count=0;
    for(ll i=0; i<31; i++){
        count=0;
        for(ll j=0; j<len; j++){
            if((1<<i)&A[j])
                count++;
        }
        ans=(ans+(2*count*(len-count)))%MOD;
    }
    int ans1=(int)ans;
    return ans1;
}
