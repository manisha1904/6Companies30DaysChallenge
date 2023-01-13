// Problem Link - https://leetcode.com/problems/number-of-matching-subsequences/description/

class Solution {
public:
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length();
        int m = words.size();
        int count=0;
        unordered_map<string,int>mp;
        for(auto&word:words){
            mp[word]++;
        }
        for(auto& x:mp){
            string t = x.first;
            int len=t.length();
            int i=0,j=0;
            while(i<n && j<len){
                if(t[j]==s[i]){
                    j++;
                    i++;
                }else
                    i++;
            }
            if(j==len)
                count+=x.second;
        }
        return count;
        
    }
};
