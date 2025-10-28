class Solution {
public:

    bool valid(vector<int> nums, int start, int direction) {
        int n = nums.size();
        int current = start;

        while (current >= 0 && current < n) {
            if (nums[current] == 0) {
                current += direction;
            } else {
                nums[current]--;
                direction *= -1;
                current += direction;
            }
        }

        for (auto i : nums) {
            if (i != 0) {
                return false;
            }
        }

        return true;
    }

    int countValidSelections(vector<int>& nums) {
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (valid(nums, i, 1)) {
                    n++;
                }

                if (valid(nums, i, -1)) {
                    n++;
                }
            }
        }

        return n;
    }
};
