class Solution {
public:
//tc = O(n logn)
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        //(num,freq)
        map<int, int> freq;
        for (int& h : hand) {
            freq[h]++; 
        }
        while (!freq.empty()) {
            int curr = freq.begin()->first;
            //checking consec nums
            for (int i = 0; i < groupSize; i++) {
                if (freq[curr + i] == 0) {
                    return false;
                }
                freq[curr + i]--;
                //erasing num if freq becomes 0
                if (freq[curr + i] == 0) {
                    freq.erase(curr + i);
                }
            }
        }
        return true;
    }
};