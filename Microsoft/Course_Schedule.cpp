Problem Link - leetcode.com/problems/course-schedule/description/
  
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<bool>course(numCourses,false);
        vector<vector<int>>adj(numCourses);
        for(auto& pre:prerequisites){
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            course[u]=true;
            for(auto& v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0)
                q.push(v);
            }
        }
        for(int i=0;i<numCourses;i++){
            if(course[i]==false)
            return false;
        }
        return true;
    }
};
