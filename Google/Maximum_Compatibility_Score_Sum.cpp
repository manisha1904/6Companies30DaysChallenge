// Problem Link - https://leetcode.com/problems/maximum-compatibility-score-sum/description/

class Solution {
public:
int calCompatibiltiy(int i,int j,vector<vector<int>>& students,vector<vector<int>>& mentors){
    int n = students[0].size();
    int cnt=0;
    for(int k=0;k<n;k++){
        if(students[i][k]==mentors[j][k])
        cnt++;
    }
    return cnt;
}
int helper(int i,int m,vector<vector<int>>&students,vector<vector<int>>& mentors,vector<bool>& visited){
    if(i==m)return 0;
    int ans=0;
    for(int j=0;j<m;j++){
        if(!visited[j]){
            visited[j]=true;
            ans=max(ans,calCompatibiltiy(i,j,students,mentors)+helper(i+1,m,students,mentors,visited));
            visited[j]=false;
        }
    }
    return ans;
}
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<bool>visited(students.size(),false);
        return helper(0,students.size(),students,mentors,visited);
    }
};
