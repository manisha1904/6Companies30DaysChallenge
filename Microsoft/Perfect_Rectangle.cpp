Problem Link - leetcode.com/problems/perfect-rectangle/description/
  
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>mp;
        for(auto& rect:rectangles){
            mp[{rect[0],rect[1]}]++;
            mp[{rect[2],rect[3]}]++;
            mp[{rect[0],rect[3]}]--;
            mp[{rect[2],rect[1]}]--;
        }
        int vertex=0;
        for(auto& point:mp){
            if(point.second!=0){
                if(abs(point.second)!=1)
                return false;
                vertex++;
            }
        }
        return vertex==4;
        
    }
};
