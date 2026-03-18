class Solution {
public:
    // starting with the highest freq letter
    bool safeChar(string& ans, char ch) {
        int n = ans.size();
        // both last two char are equal then we cant use sme char thrice
        if (n >= 2 && ans[n - 1] == ch && ans[n - 2] == ch) {
            return false;
        }
        return true;
    }
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        while (true) {
            bool aSafe = a > 0 && safeChar(ans, 'a');
            bool bSafe = b > 0 && safeChar(ans, 'b');
            bool cSafe = c > 0 && safeChar(ans, 'c');
            if (!aSafe && !bSafe && !cSafe)
                break;

            if (aSafe && a >= b && a >= c) {
                ans += 'a';
                a--;
            } else if (bSafe && b >= a && b >= c) {
                ans += 'b';
                b--;
            } else if(cSafe && c >= a && c >= b) {
                ans += 'c';
                c--;
            } else if(aSafe){
                ans += 'a';
                a--;
            }else if(bSafe){
                ans += 'b';
                b--;
            }else if(cSafe){
                ans += 'c';
                c--;
            }
        }
        return ans;
    }
};