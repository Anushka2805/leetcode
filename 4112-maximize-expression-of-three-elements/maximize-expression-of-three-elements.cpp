class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
     sort(nums.begin(),nums.end(),greater<int>());
     int n = nums.size();
     int a = nums[0];
     int b = nums[1];
     int c = nums[n-1];  
     return a+b-c; 
    }
};