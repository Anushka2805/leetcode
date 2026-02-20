class Solution {
public:
    void starF(string& s) {
        if (!s.empty()) {
            s.pop_back();
        }
    }
    void hashF(string& s) { s = s + s; }
    void percentF(string& s) { reverse(s.begin(), s.end()); }
    string processStr(string s) {
        string ans = "";
        for(char c : s){
            if(c >= 'a' && c<= 'z'){
                ans.push_back(c);
            }
            else if(c == '*'){
                starF(ans);
            }
            else if(c == '#'){
                hashF(ans);
            }
            else if(c == '%'){
                percentF(ans);
            }
        }
        return ans;
    }
};