#define ll long long
class Solution {
public:
    string longestPalindrome(string s) {
        ll ans=1;
        string s1;
        ll LPS[1000][1000];
        ll n=s.length();
        memset(LPS, 0, sizeof(LPS));
        for(ll i=0; i<n; i++){
            LPS[i][i]=1;
        }
        s1=s[0];
        for(ll i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                LPS[i][i+1]=1;
                ans=2;
                s1=s.substr(i, 2);
            }
        }
        for(ll k=3; k<=n; k++){
            for(ll i=0; i<n; i++){
                if(i+k-1>n-1)
                    continue;
                if(s[i]==s[i+k-1] && LPS[i+1][i+k-2]==1){
                    LPS[i][i+k-1]=1;
                    if(k>ans){
                        s1=s.substr(i,k);
                        ans=k;
                        // cout<<ans<<" ";
                    }
                }
            }
        }
        return s1;
    }
};
