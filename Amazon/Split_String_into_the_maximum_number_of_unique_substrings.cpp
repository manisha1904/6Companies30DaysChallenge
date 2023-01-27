// Problem Link - https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/

class Solution {
public:
unordered_set<string>st;
int res=0;
void dfs(string s,int idx,int n,string curr,int cnt){
    if(idx>=n){
        res=max(res,cnt);
        return;
    }
    curr+=s[idx];
    if(st.find(curr)==st.end()){
        st.insert(curr);
        cnt++;
        dfs(s,idx+1,n,"",cnt);
        st.erase(curr);
        cnt--;
    }
    dfs(s,idx+1,n,curr,cnt);
}
    int maxUniqueSplit(string s) {
        
        int n = s.length();
        string temp="";
        int cnt=0;
        dfs(s,0,n,temp,cnt);
        
        return res;
    }
};
