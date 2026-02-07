class Solution {
public:
    // left side mei A
    // right side mei B
    // no A should be there in right side of B
    int minimumDeletions(string s) {
        stack<char> st;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && s[i] == 'a' && st.top() == 'b') {
                st.pop();
                count++;
            } else {
                st.push(s[i]);
            }
        }
        return count;
    }
};