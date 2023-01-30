// Problem Link - https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/

class Solution {
public:
int dfs(int currPos,int endPos,int remSteps,vector<vector<int>>& dp){
    if(currPos==endPos && remSteps==0)return 1;
    if(remSteps<=0)return 0;
    if(dp[currPos][remSteps]!=-1)return dp[currPos][remSteps];
    return dp[currPos][remSteps]=(dfs(currPos+1,endPos,remSteps-1,dp)+dfs(currPos-1,endPos,remSteps-1,dp))%1000000007;
}
    int numberOfWays(int startPos, int endPos, int k) {
        startPos+=1200;
        endPos+=1200;
        vector<vector<int>>dp(4000,vector<int>(k+1,-1));
        return dfs(startPos,endPos,k,dp);
    }
};
