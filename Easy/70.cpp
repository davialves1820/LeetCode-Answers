class Solution {
public:
    int climbStairs(int n) {
     
    if (n == 1) {
    return 1;
    } else if (n == 2) {
    return 2;
    }

    int p = 1;
    int s = 2;
    int soma = 0;
    for (int i = 2; i < n; i++) {
    soma = p + s;
    p = s;
    s = soma;
    }
    
    return soma;
    
    }
};
