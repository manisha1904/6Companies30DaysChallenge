// Problem Link - https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/

class Solution {
public:
    int findKthNumber(int n, int k) {
        int x = 1; 
        while (k > 1) {
            long cnt = 0; 
            for (long diff = 1, curr = x; curr <= n; curr *= 10, diff *= 10) 
                cnt += min(n - curr + 1, diff); 
            if (k > cnt) k -= cnt, ++x; 
            else --k, x *= 10; 
        }
        return x; 
    }
};
