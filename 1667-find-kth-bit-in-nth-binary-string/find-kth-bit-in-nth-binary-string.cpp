class Solution {
public:
    string numFunc(int n) {
        if (n == 1) {
            return "0";
        }
        string prevNum = numFunc(n - 1);
        string currNum = prevNum;
        //inverting
        for (int i = 0; i < currNum.size(); i++) {
            if (currNum[i] == '0') {
                currNum[i] = '1';
            } else {
                currNum[i] = '0';
            }
        }
        //reversing
        reverse(currNum.begin(),currNum.end());

        //concatenating
        string ans = prevNum + "1" + currNum;
        return ans;
    }
    char findKthBit(int n, int k) {
        string ans = numFunc(n);
        return ans[k-1]; //1 based indexing in ans
    }
};