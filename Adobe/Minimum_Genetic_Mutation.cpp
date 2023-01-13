// Problem Link - https://leetcode.com/problems/minimum-genetic-mutation/description/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>st;
        for(auto& x:bank)
            st.insert(x);
        int steps=0;
        if(st.find(end)==st.end())
            return -1;
        queue<string>q;
        q.push(start);
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                string temp = q.front();
                q.pop();
                if(temp==end)
                    return steps;
                st.erase(temp);
                for(int i=0;i<8;i++){
                    string t = temp;
                    t[i]='A';
                    if(st.find(t)!=st.end())
                        q.push(t);
                    t[i]='C';
                    if(st.find(t)!=st.end())
                        q.push(t);
                    t[i]='G';
                    if(st.find(t)!=st.end())
                        q.push(t);
                    t[i]='T';
                    if(st.find(t)!=st.end())
                        q.push(t);
                }
            }
            steps++;
        }
           return -1;
        
    }
};
