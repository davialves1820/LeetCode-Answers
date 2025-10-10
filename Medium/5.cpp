class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }

        int start = 0, max = 1;

        for (int i = 0; i < s.size(); i++) {
            // String de tamanho impar
            search_palindromic(s, i, i, start, max);

            // Strings de tamanho par
            search_palindromic(s, i, i+1, start, max);
        }

        return s.substr(start, max);

    }

private:
    void search_palindromic(string s, int left, int right, int& start, int& max) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        int tam = right - left - 1;
        if (tam > max) {
            start = left + 1;
            max = tam;
        }

    }
};
