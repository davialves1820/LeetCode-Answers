class Solution {
public:
    int myAtoi(string s) {

        map<char, int> numbers = {
            {'0', 0}, 
            {'1', 1}, 
            {'2', 2}, 
            {'3', 3}, 
            {'4', 4},
            {'5', 5}, 
            {'6', 6}, 
            {'7', 7}, 
            {'8', 8}, 
            {'9', 9}
        };

        int i = 0;
        int tam = s.size();

        // Pula os espaços
        while (i < tam && s[i] == ' ') {
            i++;
        }

        // Verifica o sinal, caso tenha
        bool negative = false;
        
        if (i < tam) { 
            if (s[i] == '-') {
                negative = true;
                i++; 
            } else if (s[i] == '+') {
                i++;
            }
        }

        int answer = 0;

        // Forma o número até encontrar um caractere que não seja número ou finalizou a string        
        while (i < tam && s[i] >= '0' && s[i] <= '9') {
            
            int n = numbers.at(s[i]); 

            if (negative) {

                // Verifica o limite negativo
                 if (answer > INT_MAX / 10 || (answer == INT_MAX / 10 && n >= 8)) {
                    return INT_MIN;
                }

            } else { 

                // Verifica o limite positivo
                if (answer > INT_MAX / 10 || (answer == INT_MAX / 10 && n > 7)) {
                    return INT_MAX; 
                }

            }

            answer = answer * 10 + n;
            i++;
        }
        
        return negative ? (-1) * answer : answer;
    }
};
