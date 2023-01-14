// Problem Link - https://leetcode.com/problems/maximum-matrix-sum/description/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans=0;
        int neg_cnt=0;
        int min_ele=INT_MAX;
        for(auto& ele:matrix){
            for(auto& e:ele){
                if(e<0)
                neg_cnt++;
                min_ele=min(min_ele,abs(e));
                ans+=abs(e);
            }
        }
        if(neg_cnt%2==0)
        return ans;
        return ans-2*min_ele;
    }
};
