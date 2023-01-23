// Problem Link - https://leetcode.com/problems/fruit-into-baskets/description/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
     unordered_map<int,int>mp;
     int n = fruits.size();
     int i=0,j=0;
     for(i=0,j=0;j<n;j++){
         mp[fruits[j]]++;
         if(mp.size()>2){
             mp[fruits[i]]--;
             if(mp[fruits[i]]==0)
             mp.erase(fruits[i]);
             i++;
         }
     }   
     return j-i;
    }
};
