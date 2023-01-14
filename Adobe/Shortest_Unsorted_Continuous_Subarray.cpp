// Problem Link - https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start=n,end=0;
        stack<int>st;
        
      for(int i=0;i<n;i++){
          while(!st.empty() && nums[st.top()]>nums[i])
          {
              start = min(start,st.top());
              st.pop();
          }
          st.push(i);
      }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i])
            {
                end=max(end,st.top());
                st.pop();
            }
            st.push(i);
        }
        int ans = (end-start)>0?end-start+1:0;
        return ans;
        
    }
};
