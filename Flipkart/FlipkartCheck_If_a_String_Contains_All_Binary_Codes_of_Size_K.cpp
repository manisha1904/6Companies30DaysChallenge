// Problem Link - https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int size = 1<<k;
       vector<bool>check(size,false);
        int hash = 0;
        int allOne = ~size;
        int count=0;
        int n = s.length();
        for(int i=0;i<n;i++){
           hash = ((hash << 1) & allOne) | (s[i] - '0');
            if(i>=k-1 && !check[hash]){
                check[hash]=true;
                count++;
            }
        }
        return count==size;
        
    }
};
