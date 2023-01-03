Problem Link - leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

class Solution {
public:
    int mod=1e9+7;
    int dijkstra(vector<pair<long long,long long>>graph[],int n,int src){
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>>pq;
        pq.push({0,0});
        vector<long long>path(n);
        path[src]=1;
        vector<long long>dist(n,LONG_MAX);
        dist[src]=0;
        while(!pq.empty()){
            auto x=pq.top();
            long long d=x.first;
            long long node=x.second;
            pq.pop();
            if(d>dist[node])
                continue;
            for(auto y:graph[node]){
                if(dist[y.first]>y.second+d){
                    dist[y.first]=y.second+d;
                    pq.push({dist[y.first],y.first});
                    path[y.first]=path[node];
                }
                else if(dist[y.first]==y.second+d){
                    path[y.first]=(path[y.first]+path[node])%mod;
                }
            }
        }
        return path[n-1];
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>graph[n];
        for(auto x:roads){
            long long u=x[0],v=x[1],w=x[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        return dijkstra(graph,n,0);
    }
};
