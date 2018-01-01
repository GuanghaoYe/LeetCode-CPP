class Solution {
public:
    string addBinary(string a, string b) {
        while(a.size()<b.size()) a="0"+a;
        while(b.size()<a.size()) b="0"+b;
        string ret;
        int add=0;
        for(int i=a.size()-1;i>=0;--i) {
            char cur=a[i]+b[i]-'0'+add;
            add=0;
            if(cur>='2') {
                add=1;
                cur-=2;
            }
	    string a="0";
	    a[0]=cur;
            ret=a+ret;
        }
        if(add)
            ret="1"+ret;
        return ret;
    }
    
};

