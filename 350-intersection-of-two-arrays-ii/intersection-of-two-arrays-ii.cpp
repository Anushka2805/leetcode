class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        vector<int> ans;
        for(int num : nums1){
            m1[num]++;
        }
        for(int num : nums2){
            m2[num]++;
        }
        for(auto &it : m1){
            int num = it.first;
            if(m2.count(num)){
                int freq = min(m2[num],it.second);
                while(freq){
                    ans.push_back(num);
                    freq--;
                }
            }
        }
        return ans;

    }
};