Problem Link - https://leetcode.com/problems/max-points-on-a-line/description/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2)
        return n;
        int ans=0;
        for(int i=0;i<n-1;i++){
            int dup=1;
            unordered_map<string,int>mp;
            for(int j=i+1;j<n;j++){
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1]){
                    dup++;
                }else{
                    int dx = points[i][0]-points[j][0];
                    int dy = points[i][1]-points[j][1];
                    int gcd = __gcd(dx,dy);
                    mp[to_string(dx/gcd)+"_"+to_string(dy/gcd)]++;
                }
            }
            for(auto& p:mp){
                ans=max(ans,p.second+dup);
            }
        }
        return ans;
    }
};
