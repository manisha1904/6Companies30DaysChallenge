// Problem Link - https://leetcode.com/problems/swim-in-rising-water/description/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        pq.push({grid[0][0],{0,0}});
        int dirx[]={-1,1,0,0};
        int diry[]={0,0,-1,1};
        int ans=0;
        while(!pq.empty()){
            int sz=pq.size();
            for(int i=0;i<sz;i++){
                pair<int,pair<int,int>>curr=pq.top();
                pq.pop();
                grid[0][0]=-1;
                ans=max(ans,curr.first);
                int x = curr.second.first;
                int y = curr.second.second;
                if(x==grid.size()-1 && y==grid[0].size()-1)
                return ans;
                for(int k=0;k<4;k++){
                    int new_x=x+dirx[k];
                    int new_y=y+diry[k];
                    if(new_x<0 || new_y<0 || new_x>=grid.size() || new_y>=grid.size() || grid[new_x][new_y]==-1)
                    continue;
                    pq.push({grid[new_x][new_y],{new_x,new_y}});
                    grid[new_x][new_y]=-1;
                }
            }
        }
        return -1;
    }
};
