class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_sub = 2, n = 2;

        for (int i = 2; i < nums.size(); i++) {

            if (nums[i] == nums[i-1] + nums[i-2]) {
                n++;
            } else {
                max_sub = max(max_sub, n);
                n = 2;
            }
        }

        max_sub = max(max_sub, n);
        return max_sub;
    }
};
