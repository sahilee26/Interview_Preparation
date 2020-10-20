#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    int dp[n];
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	    }
	    dp[0]=arr[0];
	    int ans=dp[0];
	    dp[1]=max(dp[0], arr[1]);
	    for(int i=2; i<n; i++){
	        dp[i]=max(dp[i-2]+arr[i], dp[i-1]);
	    }
	    cout<<dp[n-1]<<endl;
	}
	return 0;
}
