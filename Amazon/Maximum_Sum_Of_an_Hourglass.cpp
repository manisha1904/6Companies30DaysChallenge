// Problem Link - https://leetcode.com/problems/maximum-sum-of-an-hourglass/description/

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>prefix(m,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            for(int j=1;j<=n;j++){
                prefix[i][j]=prefix[i][j-1]+grid[i][j-1];
            }
        }
        int ans=0;
        for(int i=0;i<m-2;i++){
            for(int j=3;j<=n;j++){
                int curr = prefix[i][j]-prefix[i][j-3];
                curr+=prefix[i+1][j-1]-prefix[i+1][j-2];
                curr+=prefix[i+2][j]-prefix[i+2][j-3];
                ans=max(curr,ans);
            }
        }
        return ans;
    }
};
