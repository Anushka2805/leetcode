class Solution {
public:
    char kthCharacter(int k) {
        long long n = 1;
        //if n less than k then we need to keep multiplying the size by 2
        while(n<k){
            n*= 2;
        }
        int shift = 0;
        while(n>1){
            long long divide = n/2;
            if(k>divide){
                k = k-divide;
                shift++;
            }
            n = divide;
        }
        return char('a' + shift);
    }
};