class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();
        unordered_map<int,int> bulbFreq;
        for(int bulb : bulbs){
            bulbFreq[bulb]++;
        }
        vector<int> ans;
        for(auto it : bulbFreq){
            if(it.second % 2 != 0){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};