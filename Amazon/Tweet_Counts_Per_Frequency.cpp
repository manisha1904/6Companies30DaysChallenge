// Problem Link - https://leetcode.com/problems/tweet-counts-per-frequency/description/

class TweetCounts {
    unordered_map<string,vector<int>>mp;
    unordered_map<string,int>freq;
public:
    TweetCounts() {
        freq["minute"]=60;
        freq["hour"]=3600;
        freq["day"]=86400;
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string f, string tweetName, int startTime, int endTime) {
        vector<int>res;
        for(int i=0;i<=(endTime-startTime)/freq[f];i++){
            res.push_back(0);
        }
        for(auto& time:mp[tweetName]){
            if(time>=startTime && time<=endTime){
                int idx = (time-startTime)/freq[f];
                res[idx]++;
            }
        }
        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
