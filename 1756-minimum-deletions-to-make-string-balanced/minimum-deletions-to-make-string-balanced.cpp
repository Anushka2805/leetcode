class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> leftB(n, 0);
        vector<int> rightA(n, 0);
        int b = 0;
        for (int i = 0; i < n; i++) {
            leftB[i] = b;
            if (s[i] == 'b') {
                b++;
            }
        }
        int a = 0;
        for (int i = n - 1; i >= 0; i--) {
            rightA[i] = a;
            if (s[i] == 'a') {
                a++;
            }
        }
        int deletions = INT_MAX;
        for (int i = 0; i < n; i++) {
            deletions = min(deletions, leftB[i] + rightA[i]);
        }
        return deletions;
    }
};