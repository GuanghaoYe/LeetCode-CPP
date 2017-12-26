class Solution {
public:
	int dp[2005];//dp[i], LIS of first i numbers 
	int cnt[2005];// number of LIS of first i numbers
	int findNumberOfLIS(vector<int>& nums) {
		memset(dp,0,sizeof dp);
		memset(cnt,0,sizeof cnt);
		for(int i=0;i<nums.size();++i) {
			int cur_length=1,cur_cnt=1;
			for(int j=0;j<i;++j) {
				if(nums[j]<nums[i]) {
					if(dp[j]+1>cur_length) {
						cur_length=dp[j]+1;
						cur_cnt=cnt[j];
					} else if(dp[j]+1==cur_length) {
						cur_cnt+=cnt[j];
					}
				}
			}
			dp[i]=cur_length;
			cnt[i]=cur_cnt;
		}
		int ans=0;
		int ans_cnt=0;
		for(int i=0;i<nums.size();++i) ans=max(ans,dp[i]);
		for(int i=0;i<nums.size();++i) if(dp[i]==ans) ans_cnt+=cnt[i];
		return ans_cnt;
	}
};

