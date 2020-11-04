// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution{
public:
    int subsetXOR(vector<int> arr, int N, int K) {
        if(N==0)
            return 0;
        int elem=0, n=N;
        for (int i=0; i<N; i++){
            elem=max(elem, arr[i]);
        }
        int m=pow(2, log2(elem)+1);
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=m; i++)
          dp[0][i]=0;
        dp[0][0]=1;
        for(int i=1; i<=n; i++){    
            for(int j=0; j<=m; j++){ 
                dp[i][j]=dp[i-1][j^arr[i-1]]+dp[i-1][j];
            }
        }
        return dp[n][K];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends
