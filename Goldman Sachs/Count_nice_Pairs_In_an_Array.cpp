// Problem Link - https://leetcode.com/problems/count-nice-pairs-in-an-array/description/

class Solution {
public:
int reverse(int num){
    int ans=0;
    while(num){
        int rem = num%10;
        ans = 10*ans+rem;
        num/=10;
    }
    return ans;
}
    int countNicePairs(vector<int>& nums) {
        long count=0;
        long mod = 1e9+7;
        unordered_map<int,long>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]-reverse(nums[i])]++;
        }
        for(auto& x:mp){
            count = (count + (x.second * (x.second - 1)) / 2) % 1000000007;
        }
        return count;
    }
};
