int dp[2000][2000];
class Solution {
public:
	int minDistance(string word1, string word2) {
		word1="a"+word1;
		word2="a"+word2;
		for(int i=0; i<max(word2.size(),word1.size())+5; ++i) {
			for(int j=0; j<max(word2.size(),word1.size())+5; ++j) {
				dp[i][j]=0x3f3f3f3f;
			}
		}
		dp[0][0]=0;
		for(int i=0; i<word1.size(); ++i) {
			for(int j=0; j<word2.size(); ++j) {
				int ip=i+1,jp=j+1;
				if(word1[i]==word2[j]) {
					dp[ip][jp]=dp[ip-1][jp-1];
				} else {
					dp[ip][jp]=dp[ip-1][jp-1]+1;
				}
				dp[ip][jp]=min(dp[ip][jp],dp[ip-1][jp]+1);
				dp[ip][jp]=min(dp[ip][jp],dp[ip][jp-1]+1);
			}
		}
		return dp[word1.size()][word2.size()];
	}
};


