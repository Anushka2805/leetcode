class Solution {
public:
    // brute force (will give tle as k is large)
    // every possible substr of size k should exist
    // we permutate and find all substr of length k
    // traverse and create map in s and store the freq of each if eveyrone has
    // freq >= 1 return true

    // optimised
    // total possible comb of k = 2^k
    bool hasAllCodes(string s, int k) {
        int possibleComb = pow(2, k);
        unordered_set<string> existingComb;
        int n = s.size();
        for (int i = k; i <= n; i++) {
            string subS = s.substr(i - k, k);
            if (!existingComb.count(subS)) {
                existingComb.insert(subS);
            }
        }
        if (existingComb.size() == possibleComb) {
            return true;
        }
        return false;
    }
};