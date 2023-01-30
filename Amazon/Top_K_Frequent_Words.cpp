// Problem Link - https://leetcode.com/problems/top-k-frequent-words/description/

class MyOperator{
    public:
     bool operator() (pair<int,string>& a,pair<int,string>& b){
        //cout<<a.second<<"  "<<b.second<<endl;
        if(a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
};
class Solution {
public:
   
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto& word:words){
            mp[word]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,MyOperator>pq;
        for(auto& x:mp){
            pq.push({x.second,x.first});
            if(pq.size()>k)
                pq.pop();
        }
        vector<string>ans(k);
        int m = k-1;
        while(!pq.empty()){
            ans[m--]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
