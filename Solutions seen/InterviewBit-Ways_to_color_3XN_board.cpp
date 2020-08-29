#define pb push_back
int mod=1e9+7;

struct triplet{
	int x, y, z;
};

vector<triplet> trip;

int dp[4][4][4][100005];

void initialise(){
    trip.clear();
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				if(i!=j && j!=k)
					trip.pb({i, j, k});
			}
		}	
	}
}

bool isvalid(triplet a, triplet  b){
	if(a.x==b.x || a.y==b.y || a.z==b.z)
		return false;
	return true;	
}

int Solution::solve(int A){	
	initialise();
	for(int i=1; i<=A; i++){
		for(int j=0; j<trip.size(); j++){
			if(i==1){
				dp[trip[j].x][trip[j].y][trip[j].z][i]=1;
				continue;
			}
			int temp=0;
			for(int k=0; k<trip.size(); k++){
				if(isvalid(trip[j], trip[k])){
					temp+=dp[trip[k].x][trip[k].y][trip[k].z][i-1];	
					temp%=mod;	
				}
			}
			dp[trip[j].x][trip[j].y][trip[j].z][i]=temp;		
		}
	}
	int ans=0;
	for(int i=0; i<trip.size(); i++){
		ans+=dp[trip[i].x][trip[i].y][trip[i].z][A];
		ans%=mod;
	}
	return ans;
}
