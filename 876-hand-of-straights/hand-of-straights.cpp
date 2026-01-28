class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        map<int, int> freq;
        for (int& h : hand) {
            freq[h]++;
        }
        while (!freq.empty()) {
            int curr = freq.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                if (freq[curr + i] == 0) {
                    return false;
                }
                freq[curr + i]--;
                if (freq[curr + i] < 1) {
                    freq.erase(curr + i);
                }
            }
        }
        return true;
    }
};