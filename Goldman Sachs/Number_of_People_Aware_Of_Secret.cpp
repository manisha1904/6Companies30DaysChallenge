// Problem Link - https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/

class Solution {
public:
long dp[1001];
long mod = 1e9+7;
int helper(int day,int n,int delay,int forget){
    if(dp[day]!=-1)
    return dp[day];
    long ans=0;
    ans++;
    if(day+forget<=n)
    ans--;
    for(int start=day+delay;start<min(n+1,day+forget);start++){
        ans+=helper(start,n,delay,forget);
        ans%=mod;
    }
    return dp[day]=ans;
}
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp,-1,sizeof(dp));
        return helper(1,n,delay,forget);
    }
};
