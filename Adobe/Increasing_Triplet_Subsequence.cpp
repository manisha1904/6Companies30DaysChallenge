// Problem Link - https://leetcode.com/problems/increasing-triplet-subsequence/description/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
            return false;
        int n = nums.size();
        int ngr[n];
        int nsl[n];
        memset(ngr,0,n);
        memset(nsl,0,n);
        nsl[0]=-1;
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            nsl[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        st.push(n-1);
        ngr[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i])
                st.pop();
            ngr[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        for(int i=1;i<n-1;i++){
            if(nsl[i]!=-1 && ngr[i]!=-1)
                return true;
        }
        return false;
        
        
    }
};
