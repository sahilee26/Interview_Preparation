class Solution {
public:      
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int len=startTime.size();
        vector<pair<pair<int, int> , int> > v;
        for(int i=0; i<len; i++){
            v.push_back({{startTime[i], endTime[i]}, profit[i]});
        }
        sort(v.begin(), v.end());
        int ans=0;
        int dp[len];
        memset(dp, 0, sizeof(dp));
        dp[0]=v[0].second;
        
        for(int i=1; i<len; i++){
            dp[i]=v[i].second;
            for(int j=0; j<i; j++){
                if(v[j].first.second<=v[i].first.first && dp[i]<dp[j]+v[i].second){   
                    dp[i]=dp[j]+v[i].second;
                }
            }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};
