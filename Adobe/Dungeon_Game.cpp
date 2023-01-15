// Problem Link - https://leetcode.com/problems/dungeon-game/description/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();   
        if(r == 0) return 0;
        int c = dungeon[0].size();
        vector<vector<int>>dp(r+1,vector<int>(c+1,INT_MAX));
        dp[r-1][c] = 1;
        dp[r][c-1] = 1;
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                int val = min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = max(1,val); 
            }
        }
        return dp[0][0];
    }
};
