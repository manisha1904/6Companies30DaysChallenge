Problem Link - https://leetcode.com/problems/factorial-trailing-zeroes/description/

class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        int i=5;
        while(i<=n){
            count+=(n/i);
            i*=5;
        }
        return count;
    }
};
