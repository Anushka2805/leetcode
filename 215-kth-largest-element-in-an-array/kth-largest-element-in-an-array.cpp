class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        int count = 0;
        int num = 0;
        while (count < k) {
            num = pq.top();
            pq.pop();
            count++;
        }
        return num;
    }
};