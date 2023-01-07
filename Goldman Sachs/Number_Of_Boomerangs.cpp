// Problem Link - https://leetcode.com/problems/number-of-boomerangs/description/

class Solution {
public:
    int distance(int x1,int y1,int x2,int y2){
        int x=abs(x1-x2);
        int y=abs(y1-y2);
        return (x*x+y*y);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        for(int i=0;i<n;i++){
            int first_x=points[i][0];
            int first_y=points[i][1];
            unordered_map<int,int>m;
            for(int j=0;j<n;j++){
                if(i!=j){
                    int second_x=points[j][0];
                    int second_y=points[j][1];
                    int dist=distance(first_x,first_y,second_x,second_y);
                    m[dist]++;
                }
            }
            for(auto x:m){
                ans+=(x.second*(x.second-1));
            }
            m.clear();
        }
        return ans;
        
    }
};
