// Problem Link - https://leetcode.com/problems/network-delay-time/submissions/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto& time:times)
            graph[time[0]-1].push_back({time[1]-1,time[2]});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k-1});
        vector<int>dist(n,INT_MAX);
        vector<bool>visited(n,false);
        dist[k-1]=0;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int w = temp.first;
            int u = temp.second;
            visited[u]=true;
            for(int i=0;i<graph[u].size();i++){
                int v = graph[u][i].first;
                int wt = graph[u][i].second;
                if(!visited[v] && dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
                
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX)
                return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
        
    }
};
