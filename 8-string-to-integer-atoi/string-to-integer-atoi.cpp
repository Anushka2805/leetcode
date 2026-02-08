class Solution {
public:
    int n;
    int sign = 1;
    long long f(string& s, int i, long long num) {
        //handling non dig or if index reaches end
        if (i >= n || s[i] < '0' || s[i] > '9') {
            return num;
        }
        int dig = s[i] - '0';
        num = num * 10 + dig;
        //out of bound cndn
        if (sign == 1 && num > INT_MAX) {
            return INT_MAX;
        }
        if (sign == -1 && -num < INT_MIN) {
            return (long long)INT_MAX + 1;
        }
        return f(s, i + 1, num);
    }
    int myAtoi(string s) {
        n = s.size();
        int i = 0;
        //space cndn
        while (i < n && s[i] == ' ') {
            i++;
        }
        //sign cndn
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        long long num = f(s, i, 0);
        num = num * sign;
        //out of bound cndn
        if (num > INT_MAX) {
            return INT_MAX;
        }
        if (num < INT_MIN) {
            return INT_MIN;
        }
        return (int)num;
    }
};