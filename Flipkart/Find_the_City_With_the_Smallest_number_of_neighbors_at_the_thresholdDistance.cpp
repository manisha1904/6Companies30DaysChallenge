// Problem Link - https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,10001));
        for(auto& edge:edges){
            adj[edge[0]][edge[1]]=adj[edge[1]][edge[0]]=edge[2];
        }
        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        int ans,count=n;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(adj[i][j]<=distanceThreshold)
                temp++;
            }
            if(temp<=count){
                count=temp;
                ans=i;
            }
        }
        return ans;
    }
};
