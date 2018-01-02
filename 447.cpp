class Solution {
    int dist2(pair<int,int> a,pair <int,int> b) {
        return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
    }
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto i:points) {
            mp.clear();
            for(auto j:points) {
                if(i==j) continue;
                mp[dist2(i,j)]++;
            }
            for(auto j:mp) {
                if(j.second>1) {
                    ans+=(j.second-1)*j.second;
                }
            }
        }
        return ans;
    }
};