class Solution {
public:
    int f(string s, char st) {
        int count = 0;
        if (s[0] != st) {
            s[0] = st;
            count++;
        }
        char prev = s[0];

        for (int i = 1; i < s.size(); i++) {
            if (prev == '0' && s[i] == '0') {
                s[i] = '1';
                count++;
            } else if (prev == '1' && s[i] == '1') {
                s[i] = '0';
                count++;
            }
            prev = s[i];
        }
        return count;
    }
    int minOperations(string s) {
        int ans = min(f(s, '0'), f(s, '1'));
        return ans;
    }
};