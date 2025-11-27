class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
        
        // Para cada classe de módulo, queremos o MENOR prefix sum encontrado
        vector<long long> best(k, LLONG_MAX);
        long long ans = LLONG_MIN;

        best[0] = 0; // prefix[0] tem "tamanho" 0 (0 % k = 0)

        for (int i = 1; i <= n; i++) {
            int mod = i % k;

            // Podemos formar subarray válido terminando em i-1 se já existe prefix anterior com mesmo modulo
            if (best[mod] != LLONG_MAX) {
                ans = max(ans, pref[i] - best[mod]);
            }

            // Atualiza melhor prefix para esta classe
            best[mod] = min(best[mod], pref[i]);
        }

        return ans;
    }
};
