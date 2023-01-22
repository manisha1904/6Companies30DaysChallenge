// Problem Link - https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int maxn=0;
        if(special[0]>bottom){
            maxn=special[0]-bottom;
        }
        int n = special.size();
        if(top>special[n-1]){
            maxn=max(maxn,top-special[n-1]);
        }
        for(int i=1;i<n;i++){
            maxn=max(maxn,special[i]-special[i-1]-1);
        }
return maxn;
    }
};
