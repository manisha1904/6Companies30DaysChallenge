// Problem Link - https://leetcode.com/problems/random-pick-with-weight/description/

class Solution {
public:
vector<int>wt;
    Solution(vector<int>& w) {
        for(auto& x:w){
            if(wt.empty())
            wt.push_back(x);
            else
            wt.push_back(wt.back()+x);
        }
    }
    
    int pickIndex() {
        int num = rand()%wt.back();
        auto idx = upper_bound(wt.begin(),wt.end(),num);
        return idx-wt.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
