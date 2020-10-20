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
	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	    }
	    int max_excl=0;
	    int max_incl=arr[0];
	    for(int i=1; i<n; i++){
	        int temp=max(max_incl, max_excl);
	        max_incl=max_excl+arr[i];
	        max_excl=temp;
	    }
	    cout<<max(max_excl, max_incl)<<endl;
	}
	return 0;
}
