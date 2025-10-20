class Solution {
public:
    int reverse(int x) {
        int reverse = 0;

        while (x != 0) {
            int n = x % 10;

            // Verifica o limite positivo 2^31 - 1
            if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && n > 7)) {
                return 0; 
            }
            
            // Verifica o limite negativo -2^31
            if (reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && n < -8)) {
                return 0; 
            }

            reverse = reverse * 10 + n;
            x /= 10;
        }
        return reverse;
    }
};
