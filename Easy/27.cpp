class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos_a = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[pos_a] = nums[i];
                pos_a++;
            } 
        }
        return pos_a;
    }
};
