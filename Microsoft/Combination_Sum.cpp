Problem Link - https://leetcode.com/problems/combination-sum-iii/description/

class Solution {
public:
    vector<vector<int>>ans;
    int sum(vector<int>&v){
        int s=0;
        for(auto& x:v)
            s+=x;
        return s;
    }
    void solve(int k,int n,vector<int>&temp,int num){
        if(k==0){
            if(sum(temp)==n)
                ans.push_back(temp);
            return;
        }
        if(num>9)
            return;
        temp.push_back(num);
        solve(k-1,n,temp,num+1);
        temp.pop_back();
        solve(k,n,temp,num+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(k,n,temp,1);
        return ans;
    }
};
