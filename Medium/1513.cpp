class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7; // Evitar overflow
        long long count = 0;  // '1's consecutivos
        long long result = 0; // Total de substrings

        for (char c : s) {
            if (c == '1') {
                count++;
                result = (result + count) % MOD;
            } else {
                count = 0;
            }
        }

        return result;
    }
};
