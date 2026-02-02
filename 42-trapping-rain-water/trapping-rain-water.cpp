class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int curr = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int l = st.top();
                int ht = min(height[l], height[i]) - height[curr];
                int w = i - l - 1;
                ans += (ht * w);
            }
            st.push(i);
        }
        return ans;
    }
};