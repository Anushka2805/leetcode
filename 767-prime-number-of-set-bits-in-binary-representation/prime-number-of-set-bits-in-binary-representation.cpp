class Solution {
public:
//10^6 almost equal to 2^20
//so almost 20 places we have that can be filled with either 0 or 1
//so to check we will make set of prime nums and then check number of bits from them 
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primeNum  = {2,3,5,7,11,13,17,19};
        int count = 0;
        for(int i = left;i<=right;i++){
            int bits1 = __builtin_popcount(i);
            if(primeNum.count(bits1)){
                count++;
            }
        }
        return count;
    }
};