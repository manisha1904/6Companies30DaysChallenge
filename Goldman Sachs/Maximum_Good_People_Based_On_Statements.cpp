// Problem Link - https://leetcode.com/problems/maximum-good-people-based-on-statements/description/

class Solution {
public:
    int countBits(int mask) {
        int cnt = 0;
        while(mask) {
            cnt += mask & 1;
            mask >>= 1;
        }
        return cnt;
    }
    int isGood(int mask, int i) {
        return mask & (1 << i);
    }
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int mask = 1 << n;
        int ans = 0;
        for(int s = mask - 1; s >= 0; --s) {
            int isValid = true;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(isGood(s, i)) {
                        if((statements[i][j] == 0 && isGood(s, j)) || (statements[i][j] == 1 && !isGood(s, j))) {
                            isValid = false;
                            break;
                        }
                    }
                }
                if(!isValid) break;
            }
            if(isValid) {
                ans = max(ans, countBits(s));
            }
        }
        return ans;
    }
};
