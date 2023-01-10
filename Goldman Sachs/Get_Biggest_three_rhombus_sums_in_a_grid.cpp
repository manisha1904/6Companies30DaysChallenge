// Problem Link - https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> R(m, vector<int>(n, 0));
        vector<vector<int>> L(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){ // To fill the diagonals going to the bottom right side with prefix sum of diagonals
            for(int j=0; j<n; j++){
                if(i-1>=0 && j-1>=0){
                    R[i][j]=grid[i][j]+R[i-1][j-1];
                } else {
                    R[i][j]=grid[i][j];
                }
            }
        }
        for(int i=0; i<m; i++){ // To fill the diagonals going to the bottom left side with prefix sum of diagonals
            for(int j=n-1; j>=0; j--){
                if(i-1>=0 && j+1<n){
                    L[i][j]=grid[i][j]+L[i-1][j+1];
                } else {
                    L[i][j]=grid[i][j];
                }
            }
        }
        vector<int> res;
        for(int i=0; i<m; i++){ // For each i, j iterate over k
            // 4 corners of rhombus = (i,j), (i+k, j-k), (i+k, j+k), (i+2*k, j)
            for(int j=0; j<n; j++){
                int k=0;
                while((i+2*k)<m && j+k<n && j-k>=0){
                    int sum=0;
                    sum+=R[i+k][j+k]-R[i][j]+grid[i][j]; // Add side value sum from (i,j) to (i+k, j+k)
                    sum+=L[i+k][j-k]-L[i][j]; // Add side value sum from (i,j) to (i+k, j-k)
                    sum+=R[i+(2*k)][j]-R[i+k][j-k]; // Add side value sum from (i+k,j-k) to (i+2*k, j)
                    sum+=L[i+(2*k)][j]-L[i+k][j+k]; // Add side value sum from (i+k,j+k) to (i+2*k, j)
                    if(k>0)
                        sum-=grid[i+(2*k)][j]; // We have added this twice during the last 2 steps if k>0
                    res.push_back(sum);
                    k++;
                }
            }
        }
        sort(res.begin(), res.end()); // Sort to remove duplicate elements in next step
        res.erase(unique(res.begin(), res.end()), res.end());
        int sz=res.size();
        // To return greatest min(3, res.size()) values
        if(sz==1){
            return {res[0]};
        } else if(sz==2){
            return {res[1], res[0]};
        } else {
            return {res[sz-1], res[sz-2], res[sz-3]};
        }
    }
};
