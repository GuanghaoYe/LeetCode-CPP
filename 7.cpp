class Solution {
public:
    int reverse(int x) {
        long long ret=0;
        long long k=x;
        if(k<0) k*=-1; 
        while(x) {
            ret=ret*10+x%10;
            x/=10;
        }
        if(x<0)ret*=-1;
        return ret>INT_MAX||ret<INT_MIN?  0 : ret;
    }
};