// Problem Link - https://leetcode.com/problems/number-of-closed-islands/description/

class Solution {
public:
    bool isValid(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j){
        if(visited[i][j] || grid[i][j])
            return false;
        return true;
    }
    bool dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j,int n,int m){
        if(!isValid(grid,visited,i,j))
            return true;
        if(i==0 || j==0 || i==n-1 || j==m-1)
            return false;
        bool check=true;
        visited[i][j]=true;
        bool left = dfs(grid,visited,i,j-1,n,m);
        bool right = dfs(grid,visited,i,j+1,n,m);
        bool up = dfs(grid,visited,i-1,j,n,m);
        bool down = dfs(grid,visited,i+1,j,n,m);
        return left && right && up && down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !visited[i][j]){
                    if(dfs(grid,visited,i,j,n,m))
                        count++;
                }
            }
        }
        return count;
    }
};
