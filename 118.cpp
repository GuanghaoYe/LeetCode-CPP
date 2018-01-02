class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ret;
        if(numRows>=1) {
            vector<int> v;
            v.push_back(1);
            ret.push_back(v);
            v.clear();
            for(int i=2;i<=numRows;++i) {
                v.clear();
                v.push_back(1);
                for(int j=1;j<i-1;++j) {
                    v.push_back(ret[i-2][j]+ret[i-2][j-1]);
                }
                v.push_back(1);
                ret.push_back(v);
            }
        }
        return ret;
    }
};