class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int HH = 0; HH <= 11; HH++) {
            for (int MM = 0; MM <= 59; MM++) {
                //checking if all combos bits = turnedon 
                if (__builtin_popcount(HH) + __builtin_popcount(MM) ==
                    turnedOn) {
                    string hr = to_string(HH);
                    //if min is less than 10 then we insert 0 first and then the other digit
                    string min = (MM < 10 ? "0" : "") + to_string(MM);
                    ans.push_back(hr + ":" + min);
                }
            }
        }
        return ans;
    }
};