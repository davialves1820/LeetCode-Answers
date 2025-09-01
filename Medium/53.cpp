class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int largest_sum = nums[0];
        int current_sum = 0;

        for (auto n : nums) {
            
            current_sum += n;
            if (current_sum > largest_sum) {
                largest_sum = current_sum;
            }
            if (current_sum < 0) {
                current_sum = 0;
            } 
            
        }
        return largest_sum;
    }
};
