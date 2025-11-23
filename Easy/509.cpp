class Solution {
public:
    int fib(int n) {
        
        if (n == 0) {
            return 0;
        }
        
        vector<int> r(n+1);
        r[0] = 0;
        r[1] = 1;

        for (int i = 2; i <= n; i++) {
            r[i] = r[i-2] + r[i-1];
        }

        return r[n];
    }
};
