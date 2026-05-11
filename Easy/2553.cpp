class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (auto v : nums) {
            vector<int> temp;
            while (v > 0) {
                temp.push_back(v % 10);
                v = v / 10;
            }

            for (int i = temp.size() - 1; i >= 0; i--) {
                ans.push_back(temp[i]);
            }
        }

        return ans;
    }
};
