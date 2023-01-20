// Problem Link - https://leetcode.com/problems/custom-sort-string/description/

class Solution {
public:
    string customSortString(string order, string s) {
        int count[128]={0};
        for(auto& c:s){
            count[c-'a']++;
        }
        int i=0;
        for(auto& c:order){
            while(count[c-'a']>0){
                s[i++]=c;
                --count[c-'a'];
            }
        }
        for(char ch='a';ch<='z';ch++){
            while(count[ch-'a']){
                s[i++]=ch;
                --count[ch-'a'];
            }
        }
        return s;
    }
};
