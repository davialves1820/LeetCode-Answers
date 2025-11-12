class Solution {
public:
    int divide(int dividend, int divisor) {
        
        // Caso especial: INT_MIN / -1 = overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Converter para long long e pega o valor absoluto
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);
        long long d = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            // Dobra o divisor a cada interação
            while (a >= temp + temp) {
                temp = temp + temp;
                multiple = multiple + multiple;
            }

            a = a - temp;
            d = d + multiple;
        }

        // Ajusta o sinal
        if ((dividend < 0 && divisor >= 0) || (dividend >= 0 && divisor < 0)) {
            d = -d;
        }

        return d;
    }
};
