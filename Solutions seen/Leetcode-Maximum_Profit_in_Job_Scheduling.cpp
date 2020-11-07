class Solution {
public: 
    
    int BinarySearch(pair<pair<int, int> , int>  v[], int pos){
        int low=0, high=pos-1, mid;
        while(low<=high){
            mid=(high+low)/2;
            if(v[mid].first.first<=v[pos].first.second){
               if(v[mid+1].first.first<=v[pos].first.second)
                    low=mid+1;
                else
                    return mid;
            }   
            else
                high=mid-1;
        }
        return -1;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int len=startTime.size();
        pair<pair<int, int> , int>  v[len];
        for(int i=0; i<len; i++){
            v[i]={{endTime[i], startTime[i]}, profit[i]};
        }
        sort(v, v+len);
        int ans=0;
        int dp[len];
        memset(dp, 0, sizeof(dp));
        dp[0]=v[0].second;
        
        for(int i=1; i<len; i++){
            int pos=BinarySearch(v, i);
            int temp=v[i].second;
            if(pos!=-1)
                temp+=dp[pos];
            dp[i]=max(dp[i-1], temp);
        }
        return dp[len-1];
    }
};
