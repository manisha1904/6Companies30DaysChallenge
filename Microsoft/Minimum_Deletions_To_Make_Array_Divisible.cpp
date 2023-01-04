Problem Link - leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int,int>mp;
        unordered_map<int,int>mp2;
        for(auto& num:nums){
            mp[num]++;
        }
        for(auto& num:numsDivide){
            mp2[num]++;
        }
        int count=0;
        for(auto& x:mp){
            bool flag=true;
            for(auto& y:mp2){
                if(y.first%x.first){
                    flag=false;
                    break;
                }
            }
            if(flag)
            return count;
            count+=x.second;
        }
        return -1;
    }
};
