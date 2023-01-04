Problem Link - leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0,l=0,r=0,n=s.length();
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            while(mp['a'] && mp['b'] && mp['c']){
                count+=(n-r);
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return count;
    }
};
