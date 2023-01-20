// Problem Link - https://leetcode.com/problems/max-area-of-island/description/

class Solution {
public:
    int x[4]={-1,0,0,1};
    int y[4]={0,-1,1,0};
    bool isValid(int i,int j,int m,int n){
        return (i>=0 && j>=0 && i<m && j<n);
    }
    int helper(vector<vector<int>>& grid,int m,int n,int i,int j,vector<vector<bool>>& visited){
        if(i==m || j==n || visited[i][j])
            return 0;
        visited[i][j]=true;
        int temp_area=1;
        for(int dir=0;dir<4;dir++){
            int temp_x=i+x[dir];
            int temp_y=j+y[dir];
            if(isValid(temp_x,temp_y,m,n) && !visited[temp_x][temp_y] && grid[temp_x][temp_y]==1){
                temp_area+=helper(grid,m,n,temp_x,temp_y,visited);
            }
        }
        return temp_area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int max_area=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int temp_area = helper(grid,m,n,i,j,visited);
                    max_area = max(max_area,temp_area);
                }
            }
        }
        return max_area;
    }
};
