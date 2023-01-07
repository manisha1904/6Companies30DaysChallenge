// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>mp;
        int ans=cards.size()+1;
        int n=cards.size();
        for(int i=0;i<n;i++){
            int val = cards[i];
            if(mp.find(val)!=mp.end()){
                ans=min(ans,i-mp[val]+1);
            }
            mp[val]=i;
        }
        return ans==n+1?-1:ans;
    }
};
