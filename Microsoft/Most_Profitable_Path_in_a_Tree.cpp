Problem Link - leetcode.com/problems/most-profitable-path-in-a-tree/description/
  
class Solution {
public:
bool dfs(int src,int time,unordered_map<int,int>& path,vector<bool>& visited,vector<int>adj[]){
    visited[src]=true;
    path[src]=time;
    if(src==0)
    return true;
    for(auto& dest:adj[src]){
        if(!visited[dest] && dfs(dest,time+1,path,visited,adj))
        return true;
    }
    path.erase(src);
    return false;
}
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<int>adj[n];
        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_map<int,int>path;
        vector<bool>visited(n,false);
        dfs(bob,0,path,visited,adj);
        int ans = INT_MIN;
        queue<vector<int>>q;
        q.push({0,0,0});
        visited.assign(n,false);
        while(!q.empty()){
            int src = q.front()[0];
            int time = q.front()[1];
            int income = q.front()[2];
            visited[src]=true;
            q.pop();
            if(path.find(src)==path.end() || time<path[src]){
                income+=amount[src];
            }else if(time==path[src]){
                income+=(amount[src]/2);
            }
            if(adj[src].size()==1 && src!=0){
                ans = max(ans,income);
            }
            for(auto& dest:adj[src]){
                if(!visited[dest]){
                    q.push({dest,time+1,income});
                }
            }

        }
        return ans;
    }
};
