// Problem Link - https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        priority_queue<int>max_ele;
        priority_queue<int,vector<int>,greater<>>min_ele;
        for(auto& pile:piles){
            max_ele.push(pile);
            min_ele.push(pile);
        }
        int cnt=0,ans=0;
        while(cnt<piles.size() && !max_ele.empty() && !min_ele.empty()){
            int alice = max_ele.top();
            max_ele.pop();
            int me = max_ele.top();
            max_ele.pop();
            int bob = min_ele.top();
            min_ele.pop();
            cnt+=3;
            ans+=me;
        }
        return ans;
    }
};
