class Solution {
	bool check(string s1,string s2) {
		int cnt1[256],cnt2[256];
		memset(cnt1,0,sizeof cnt1);
		memset(cnt2,0,sizeof cnt2);
		for(auto i:s1) {
			cnt1[i]++;
		}
		for(auto i:s2) 
			cnt2[i]++;
		for(int i=0;i<256;++i) {
			if(cnt1[i]!=cnt2[i])
				return 0;
		}
		return 1;
	}
	public: bool isScramble(string s1, string s2) {
		if(s1.length()!=s2.length())
			return 0;
		if(!check(s1,s2))
			return 0;
		if(s1.size()<=2)
			return 1;
		for(int i=1;i<s1.size();i++) {
			string l1=s1.substr(0,i);
			string l2=s2.substr(0,i);
			string r1=s1.substr(i);
			string r2=s2.substr(i);
			if(isScramble(l1,l2)&&isScramble(r1,r2))
				return 1;
			l2=s2.substr(0,r1.size());
			r2=s2.substr(l2.size());
			if(isScramble(l1,r2)&&isScramble(l2,r1))
				return 1;

		}
		return 0;
	}
};

