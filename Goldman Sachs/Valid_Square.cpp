Problem Link - https://leetcode.com/problems/valid-square/description/

class Solution {
public:
int distance(vector<int>& p1,vector<int>& p2){
    return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
}
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int,int>mp;
        mp[distance(p1,p2)]++;
        mp[distance(p1,p3)]++;
        mp[distance(p1,p4)]++;
        mp[distance(p2,p3)]++;
        mp[distance(p2,p4)]++;
        mp[distance(p3,p4)]++;
        if(mp.find(0)!=mp.end())
        return false;
        return mp.size()==2;
    }
};
