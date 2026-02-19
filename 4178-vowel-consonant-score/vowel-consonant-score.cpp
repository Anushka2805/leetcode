class Solution {
public:
    int vowelConsonantScore(string s) {
        int n = s.size();
        int vCount = 0;
        int cCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                    s[i] == 'u') {
                    vCount++;
                } else {
                    cCount++;
                }
            }
        }
        if (cCount > 0) {
            return vCount / cCount;
        }
        return 0;
    }
};