// Problem Link - https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int n = nums[0].size();
        int m = nums.size();
        for(auto& q:queries){
            priority_queue<pair<string,int>>pq;
            for(int i=0;i<m;i++){
                string temp = nums[i].substr(n-q[1]);
                pq.push({temp,i});
                if(pq.size()>q[0])
                pq.pop();
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};
