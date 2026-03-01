class Solution {
public:
    // we need to find deci binary nos whose sum is equal to n
    // n = 32
    // 32 - 11
    // 21 - 11
    // 10 - 10 = 0
    // will choose largest deci binary num first
    int minPartitions(string n) {
        int maxDig = 0;
        for(char ch : n){
            maxDig = max(maxDig,ch-'0');
        }
        return maxDig;
    }
};