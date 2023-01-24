// Problem Link - https://leetcode.com/problems/matrix-block-sum/description/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),0));
        int temp=0;
        for(int i=0;i<=k && i<mat.size();i++){ 
        for(int j=0;j<=k && j<mat[0].size();j++){
            temp+=mat[i][j];
        }
        }
        ans[0][0]=temp;
        
            for(int i=1;i<mat.size();i++){
                
                ans[i][0]+=ans[i-1][0];
                if((i-k)>0){
                    for(int j=0;j<=k && j<mat[0].size();j++){
                        ans[i][0]-=mat[i-k-1][j];
                    }
                }
                   
                if(i+k<mat.size()){
                    for(int j=0;j<=k && j<mat[0].size();j++){
                        ans[i][0]+=mat[i+k][j];
                    }
                   
                }
                
                
            }
    
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(j==0)
                    continue;
                ans[i][j]+=ans[i][j-1];
                if((j-k)>0){
                    for(int m=((i-k)<=0?0:(i-k));m<=i+k && m<mat.size();m++){
                        ans[i][j]-=mat[m][j-k-1];
                    }
                }
                   
                if((j+k)<mat[0].size()){
                    for(int m=((i-k)<=0?0:(i-k));m<=(i+k) && m<mat.size();m++){
                        ans[i][j]+=mat[m][j+k];
                    }
                }
                    
            }
        }
        return ans;
        
        
    }
};
