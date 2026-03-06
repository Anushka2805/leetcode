class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int first0 = 0;
        int count1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (first0 >= 1) {
                    return false;
                }
                continue;
            } else {
                first0++;
                // if (first0 > 1) {
                //     return false;
                // }
            }
        }
        return true;
    }
};