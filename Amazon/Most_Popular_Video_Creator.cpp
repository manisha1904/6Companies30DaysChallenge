// Problem Link - https://leetcode.com/problems/most-popular-video-creator/description/

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,long long>views_count;
        long long max_view=0;
        int n = creators.size();
        for(int i=0;i<n;i++){
            views_count[creators[i]]+=views[i];
            if(max_view<views_count[creators[i]])
            max_view = views_count[creators[i]];
        }
        // cout<<max_view<<endl;
        unordered_map<string,long long>max_views;
        for(auto& x:views_count){
            cout<<x.second<<"  ";
            if(x.second==max_view){
                max_views[x.first]=x.second;
            }
        }
        unordered_map<string,pair<string,int>>mp;
        for(int i=0;i<n;i++){
            string creator = creators[i];
            string id = ids[i];
            int view = views[i];
            if(max_views.count(creator)){
                    if(mp.find(creator)==mp.end() || mp[creator].second<view){
                        mp[creator].first=id;
                        mp[creator].second=view;
                    }else if(mp[creator].second==view && mp[creator].first>id){
                        mp[creator].first=id;
                    }
                }
        }
        vector<vector<string>>res;
        for(auto& x:mp){
            res.push_back({x.first,x.second.first});
        }
        return res;
        
    }
};
