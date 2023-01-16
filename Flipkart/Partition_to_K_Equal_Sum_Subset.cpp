// Problem Link - https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/

class Solution {
public:
bool helper(vector<int>& nums,vector<bool>& visited,int idx,int curr_sum,int k,int target){
    if(k==1)
    return true;
    if(idx>=nums.size())
    return false;
    if(target==curr_sum)
    return helper(nums,visited,0,0,k-1,target);
    for(int j=idx;j<nums.size();j++){
        if(visited[j] || curr_sum+nums[j]>target)
        continue;
        visited[j]=true;
        if(helper(nums,visited,j+1,curr_sum+nums[j],k,target))
        return true;
        visited[j]=false;
    }
    return false;
}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1)
        return true;
        int sum=0;
        for(auto& num:nums){
            sum+=num;
        }
        if(k<=0 || sum%k!=0)return false;
        vector<bool>visited(nums.size(),false);
        return helper(nums,visited,0,0,k,sum/k);
    }
};
