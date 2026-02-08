class Solution {
public:
    double f(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        if (n == 1) {
            return x;
        }
        if (n % 2 == 0) {
            return f(x * x, n / 2);
        }
        return x* f(x * x, n /2);
    }
    double myPow(double x, int n) {
        long long num = n;
        if (num < 0) {
            return (1.0 / f(x, -1 * num));
        }
        return f(x,num);
    }
};