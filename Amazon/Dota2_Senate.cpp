// Problem Link - https://leetcode.com/problems/dota2-senate/description/

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>q1,q2;
        int n = senate.size();
        for(int i=0;i<n;i++){
            senate[i]=='R'?q1.push(i):q2.push(i);
        }
        while(!q1.empty() && !q2.empty()){
            int r_idx = q1.front(),d_idx=q2.front();
            q1.pop(),q2.pop();
            r_idx<d_idx?q1.push(r_idx+n):q2.push(d_idx+n);
        }
        return q1.size()>q2.size()?"Radiant":"Dire";
    }
};
