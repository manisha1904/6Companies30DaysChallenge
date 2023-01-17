// Problem Link - https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

class Solution {
public:
    int solve(int k,vector<int>&v,int idx){
        if(v.size()==1)
            return v[0];
        int n = v.size();
        idx = (idx+k)%n;
        v.erase(v.begin()+idx);
        return solve(k,v,idx);
    }
    int findTheWinner(int n, int k) {
        if(n==1)
            return 1;
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        return solve(k-1,v,0);
        
    }
};
