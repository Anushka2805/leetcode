class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> m;
        vector<int> ans;
        //counting 1s in arr numbers
        for(int a : arr){
            int count1 = __builtin_popcount(a);
            m.push_back({count1,a});
        }
        //sorting acc to 1s count
        sort(m.begin(),m.end());
        //pushing back corresponding number
        for(auto &it :m){
            ans.push_back(it.second);
        }
        return ans;
    }
};