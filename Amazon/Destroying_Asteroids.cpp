// Problem Link - https://leetcode.com/problems/destroying-asteroids/description/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m=mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto& ast:asteroids){
            if(m<ast)return false;
            m+=ast;
        }
        return true;
    }
};
