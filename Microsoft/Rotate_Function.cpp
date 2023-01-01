Problem Link - leetcode.com/problems/rotate-function/description/
  
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       long fn=0,sum=0;
       int n = nums.size();
       for(int i=0;i<n;i++){
           sum+=nums[i];
           fn+=(i*nums[i]);
       }
       long dp[n];
       dp[0]=fn;
       for(int i=1;i<n;i++){
           dp[i]=dp[i-1]+sum-n*nums[n-i];
           fn = max(fn,dp[i]);
       }
       return fn;

    }
};
