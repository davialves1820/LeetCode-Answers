class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visto(n, false);
        vector<int> duplicados;

        for (int num : nums) {
            if (visto[num]) {
                duplicados.push_back(num);
            } else {
                visto[num] = true;
            }
        }

        return duplicados;

    }
};
