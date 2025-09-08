class Solution {
public:
    int lengthOfLastWord(string s) {
        int tam = 0, aux = s.size() - 1;

        while (s[aux] == ' ') {
            aux--;
        }
        while (aux >= 0 && s[aux] != ' ') {
            aux--;
            tam++;
        }
        return tam;
    }
};
