class Solution {
public:
    int gcd_all(const vector<int>& nums) {
        int g = nums[0];
        
        for (int x : nums) {
            g = gcd(g, x);
        }

        return g;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int g = gcd_all(nums);

        // Caso impossível
        if (g > 1) {
            return -1;
        }

        // Caso já exista algum 1
        int ones = count(nums.begin(), nums.end(), 1);

        if (ones > 0) {
            return n - ones; // só precisamos espalhar os 1s
        }

        // Caso não exista 1 — procurar o menor subarray com gcd == 1
        int min_len = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            int g = nums[i];

            for (int j = i + 1; j < n; ++j) {
                g = gcd(g, nums[j]);
            
                if (g == 1) {
                    min_len = min(min_len, j - i + 1);
                    break; // já achou o menor para esse i
                }
            }
        }

        // (L - 1) para criar o 1 + (n - 1) para espalhar
        return (min_len - 1) + (n - 1);
        }
};
