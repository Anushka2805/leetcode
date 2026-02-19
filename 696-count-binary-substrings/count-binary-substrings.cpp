class Solution {
public:
//tc = O(n) 
//sc = O(1)
    int countBinarySubstrings(string s) {
        int count = 0;
        int prev = 0;
        int curr = 1;
        for(int i = 1;i<s.size();i++){
            if(s[i] == s[i-1]){
                curr++;
            }else{
                count += min(prev,curr);
                prev = curr;
                curr = 1;
            }
        }
        //for the last we will be out of for loop so we consider its min in final ans 
        return count + min(curr,prev);
    }
};