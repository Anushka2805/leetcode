class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        int n = asteroids.size();
        for (int a : asteroids) {
            //a is neg
            while (!st.empty() && st.top() > 0 && a < 0) {
                //value of a larger than st top
                if (abs(st.top()) < abs(a)) {
                    st.pop();
                    continue;
                }//both equal so destroying both
                 else if (abs(st.top()) == abs(a)) {
                    a = 0;
                    st.pop();
                    continue;
                }//negative one has smaller value then prev one so ommit it
                 else {
                    a = 0;
                    break;
                }
            }
            if (a != 0) {
                st.push(a);
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};