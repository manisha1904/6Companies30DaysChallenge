Problem Link - leetcode.com/problems/largest-divisible-subset/description/

class Solution {
public:
unordered_map<int,vector<int>>dp;
vector<int>solve(vector<int>& nums,int start,int n){
    if(start>=n)
    return {};
    if(dp.find(start)!=dp.end())
    return dp[start];
    for(int j=start+1;j<n;j++){
        if(nums[j]%nums[start])
        continue;
        auto temp = solve(nums,j,n);
        if(dp[start].size()<temp.size())
        dp[start]=temp;
    }
    dp[start].push_back(nums[start]);
    return dp[start];
}
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            auto temp = solve(nums,i,n);
            if(ans.size()<temp.size())
            ans = temp;
        }
        return ans;
    }
};
